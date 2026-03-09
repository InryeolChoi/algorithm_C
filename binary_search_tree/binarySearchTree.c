#include "binarySearchTree.h"

BSTNode *createNode(ElementType newdata)
{
    BSTNode *newnode = (BSTNode *)malloc(sizeof(BSTNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = newdata;

    return newnode;
}

void        *destoryNode(BSTNode *node)
{
    free(node);
}

void        *destoryTree(BSTNode *tree)
{
    if (tree->right != NULL)
        destoryNode(tree->right);
    if (tree->left != NULL)
        destoryNode(tree->left);
    
    tree->left = NULL;
    tree->right = NULL;

    destoryNode(tree);
}

BSTNode     *searchNode(BSTNode *tree, ElementType target)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->data = target)
        return tree;
    else if (tree->data > target)
        return searchNode(tree->left, target);
    else if (tree->data < target)
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

BSTNode     *removeNode(BSTNode *tree, BSTNode *parent, ElementType target)
{
    BSTNode *removed = NULL;

    if (tree == NULL)
        return NULL;
    
    if (tree->data > target)
        removed = removeNode(tree->left, tree, target);
    else if (tree->data < target)
        removed = removeNode(tree->right, tree, target);
    else
    {
        removed = tree;

        // 자식노드가 전부 없을 때
        if (tree->left == NULL && tree->right == NULL)
        {
            // 부모 노드 끊기
            if (parent->left == tree)
                parent->left = NULL;
            else
                parent->right = NULL;
        }

        // 자식노드 있을 때
        else
        {
            if (tree->left != NULL && tree->right != NULL)
            {
                BSTNode *minNode = searchMinNode(tree->right);
                minNode = removeNode(tree, NULL, minNode->data);
            }
            else
            {
                BSTNode *temp = NULL;
                if (tree->left == NULL)
                    temp = tree->left;
                else
                    temp = tree->right;
                
                if (parent->left == tree)
                    parent->left = temp;
                else
                    parent->right = temp;
            }
        }
    }
    
    return removed;
}

void        InorderPrintTree(BSTNode *node)
{

}
