#include "redblacktree.h"

extern node *Nil;

node    *createnode(elementType data)
{
    node    *newnode;
    
    newnode = malloc(sizeof(node));
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    newnode->color = BLACK; 

    return newnode;
}

void    destroynode(node *node)
{
    free(node);
}

void    destroytree(node *tree)
{
    if (tree->right != Nil)
        destorytree(tree->right);
    if (tree->left != Nil)
        destorytree(tree->left);
    
    tree->left = Nil;
    tree->right = Nil;

    destoryNode(tree);
}

/* 검색 */
node    *searchNode(node *tree, elementType target)
{
    if (tree == Nil)
        return NULL;
    
    if (tree->data < target)
        searchNode(tree->left, target);
    else if (target < tree->data)
        searchNode(tree->right, target);
    else
        return tree;
}

// 가장 작은 노드 : 왼쪽으로 가면 된다.
node    *searchMinNode(node *tree)
{
    if (tree == Nil)
        return Nil;
    
    if (tree->left == Nil)
        return tree;
    else
        searchMinNode(tree->left);
}

/* 회전 */
void    rotateLeft(node **root, node *parent)
{
    node *rightchild = parent->right;
    
    parent->right = rightchild->left;
    if (rightchild->left != Nil)
        rightchild->left->parent = parent;
    
    rightchild->parent = parent->parent;
    if (parent->parent == NULL)
        (*root) = rightchild;
    else
    {
        if (parent->parent->left == parent)
            parent->parent->left = rightchild;
        else
            parent->parent->right = rightchild;
    }

    rightchild->left = parent;
    parent->parent = rightchild;
}

void    rotateRight(node **root, node *parent)
{
    node *leftchild = parent->left;

    /* T2와 P를 연결 중 */
    parent->left = leftchild->right;
    if (leftchild->right != Nil)
        leftchild->right->parent = parent;

    /* leftchild와 P.P를 연결 중 */
    // leftchild -> P.P
    leftchild->parent = parent->parent;

    // P.P -> leftchild
    if (parent->parent == NULL)
        (*root) = leftchild;
    else
    {
        if (parent->parent->left == parent)
            parent->parent->left = leftchild;
        else
            parent->parent->right = leftchild;
    }

    // leftchild와 parent를 다시 연결
    leftchild->right = parent;
    parent->parent = leftchild;
}



void    insertNode(node **tree, node *newnode)
{
    insertNodeHelper(tree, newnode);
    
    newnode->color = RED;
    newnode->left = Nil;
    newnode->right = Nil;

    rebuildAfterInsert(tree, newnode);
}

void    insertNodeHelper(node **tree, node *newnode)
{
    if ((*tree) == NULL)
        (*tree) = newnode;
    
    if ((*tree)->data < newnode->data)
    {
        if ((*tree)->right == Nil)
        {
            (*tree)->right = newnode;
            newnode->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->right, newnode);
    }
    else if (newnode->data < (*tree)->data)
    {
        if ((*tree)->left == Nil)
        {
            (*tree)->left = newnode;
            newnode->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->left, newnode);
    }
}

void    rebuildAfterInsert(node **tree, node *newnode)
{

}



void    removeNode(node **root, elementType target);
void    rebuildAfterRemove(node **root, node *x);



void    printTree(node *node, int depth, int blackcount);
