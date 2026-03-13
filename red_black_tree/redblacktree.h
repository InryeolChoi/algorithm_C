#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct  tagRBTNode
{
    struct tagRBTNode *parent;
    struct tagRBTNode *left;
    struct tagRBTNode *right;
    enum { RED, BLACK } color;
    elementType data;
}   node;

// 생성, 삭제
node    *createnode(elementType data);
void    destroytree(node *tree);
void    destroynode(node *node);

// 탐색
node    *searchNode(node *tree, elementType target);
node    *searchMinNode(node *tree);

// 회전
void    rotateLeft(node **root, node *parent);
void    rotateRight(node **root, node *parent);

// 삽입
void    insertNode(node **tree, node *newnode);
void    insertNodeHelper(node **tree, node *newnode);
void    removeNode(node **root, elementType target);
void    rebuildAfterInsert(node **root, node *X);
void    rebuildAfterRemove(node **root, node *x);

// 출력
void    printTree(node *node, int depth, int blackcount);

#endif REDBLACKTREE_H