#include "binarySearchTree.h"

static BSTNode *removeNodeInternal(BSTNode **tree, ElementType target);

BSTNode *createNode(ElementType newdata)
{
    BSTNode *newnode = (BSTNode *)malloc(sizeof(BSTNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = newdata;

    return newnode;
}

void        destoryNode(BSTNode *node)
{
    free(node);
}

void        destoryTree(BSTNode *tree)
{
    if (tree == NULL)
        return;
    destoryTree(tree->left);
    destoryTree(tree->right);
    destoryNode(tree);
}

BSTNode     *searchNode(BSTNode *tree, ElementType target)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->data == target)
        return tree;
    else if (tree->data > target)
        return searchNode(tree->left, target);
    return searchNode(tree->right, target);
}

BSTNode     *searchMinNode(BSTNode *tree)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->left == NULL)
        return tree;
    else
        return searchMinNode(tree->left);
}

void        insertNode(BSTNode *tree, BSTNode *child)
{
    if (tree->data < child->data)
    {
        if (tree->right == NULL)
            tree->right = child;
        else
            insertNode(tree->right, child);
    }
    else if (tree->data > child->data)
    {
        if (tree->left == NULL)
            tree->left = child;
        else
            insertNode(tree->left , child);
    }
}

static BSTNode *removeNodeInternal(BSTNode **tree, ElementType target)
{
    BSTNode *removed;
    BSTNode *child;
    BSTNode *minNode;

    if (*tree == NULL)
        return NULL;

    if ((*tree)->data > target)
        return removeNodeInternal(&(*tree)->left, target);
    if ((*tree)->data < target)
        return removeNodeInternal(&(*tree)->right, target);

    removed = *tree;
    if (removed->left == NULL && removed->right == NULL)
        *tree = NULL;
    else if (removed->left == NULL || removed->right == NULL)
    {
        child = removed->left != NULL ? removed->left : removed->right;
        *tree = child;
    }
    else
    {
        minNode = searchMinNode(removed->right);
        removed->data = minNode->data;
        return removeNodeInternal(&removed->right, minNode->data);
    }

    removed->left = NULL;
    removed->right = NULL;
    return removed;
}

BSTNode     *removeNode(BSTNode **tree, ElementType target)
{
    if (tree == NULL)
        return NULL;
    return removeNodeInternal(tree, target);
}

void        InorderPrintTree(BSTNode *node)
{
    if (node == NULL)
        return;
    
    InorderPrintTree(node->left);
    printf("%d ", node->data);
    InorderPrintTree(node->right);
}
