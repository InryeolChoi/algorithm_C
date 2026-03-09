#ifndef BINARYSERACHTREE_H
#define BINARYSERACHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagBSTNode
{
    struct TagBSTNode   *left;
    struct TagBSTNode   *right;

    ElementType         data;
}   BSTNode;

BSTNode     *createNode(ElementType newdata);
void        *destoryNode(BSTNode *node);
void        *destoryTree(BSTNode *tree);

BSTNode     *searchNode(BSTNode *tree, ElementType target);
BSTNode     *searchMinNode(BSTNode *tree);
void        insertNode(BSTNode *tree, BSTNode *child);
BSTNode     *removeNode(BSTNode *tree, BSTNode *parent, ElementType target);
void        InorderPrintTree(BSTNode *node);

#endif