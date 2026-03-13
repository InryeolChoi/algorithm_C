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

/* 삽입 */
// 삽입의 메인
void    insertNode(node **tree, node *newnode)
{
    // 노드 삽입
    insertNodeHelper(tree, newnode);
    
    // 새 노드를 빨간색으로, 왼/오른쪽을 Nil로
    newnode->color = RED;
    newnode->left = Nil;
    newnode->right = Nil;

    // 규칙 잡기
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

void    rebuildAfterInsert(node **root, node *X)
{
    while (X != (*root) && X->parent->color)
    {
        // 
        if (X->parent == X->parent->parent->left)
        {
            node *uncle = X->parent->parent->right;
            if (uncle->color == RED)
            {
                X->parent->color = BLACK;
                uncle->color = BLACK;
                X->parent->parent->color = RED;

                X = X->parent->parent;
            }
            else
            {
                if (X == X->parent->right)
                {
                    X = X->parent;
                    rotateLeft(root, X);
                }
                
                X->parent->color = BLACK;
                X->parent->parent->color = RED;

                rotateRight(root, X->parent->parent);
            }
        }
        // 
        else
        {
            
        }
    }
}


void    removeNode(node **root, elementType target);
void    rebuildAfterRemove(node **root, node *x);



void    printTree(node *node, int depth, int blackcount);
