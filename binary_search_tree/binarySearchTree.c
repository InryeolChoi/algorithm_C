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
    
    if (tree->data == target)
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
            // 자식이 둘 있을 때
            if (tree->left != NULL && tree->right != NULL)
            {
                // 오른쪽 subtree에서 가장 작은 노드 찾기
                BSTNode *minNode = searchMinNode(tree->right);

                // 그 노드를 삭제
                minNode = removeNode(tree, NULL, minNode->data);

                // 삭제할 노드의 data를 그 값으로 교체
                tree->data = minNode->data;
            }
            // 자식이 하나만 있을 때
            else
            {
                // 자식 가지고 오기
                BSTNode *temp = NULL;
                if (tree->left == NULL)
                    temp = tree->right;
                else
                    temp = tree->right;
                
                // 조부모를 자식과 연결
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
    if (node == NULL)
        return;
    
    InorderPrintTree(node->left);
    printf("%d ", node->data);
    InorderPrintTree(node->right);
}
