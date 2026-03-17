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
        // 부모가 할아버지의 왼쪽 자식인 경우
        if (X->parent == X->parent->parent->left)
        {
            node *uncle = X->parent->parent->right;
            
            // 삼촌이 붉은 색인 경우
            if (uncle->color == RED)
            {
                X->parent->color = BLACK;
                uncle->color = BLACK;
                X->parent->parent->color = RED;

                // 처리 후 기준을 조상으로 올리는 루트 (반복)
                X = X->parent->parent;
            }
            // 삼촌이 검은색인 경우
            else
            {
                // 새 노드가 부모의 우측 아래에 있는 경우
                if (X == X->parent->right)
                {
                    // 기준노드를 부모로 바꾸고 회전
                    X = X->parent;
                    rotateLeft(root, X);
                }
                
                X->parent->color = BLACK;
                X->parent->parent->color = RED;

                rotateRight(root, X->parent->parent);
            }
        }
        // 부모가 할아버지의 오른쪽 자식인 경우
        else
        {
            node *uncle = X->parent->parent->left;
            
            if (uncle->color == RED)
            {
                X->parent->color = BLACK;
                uncle->color = BLACK;
                X->parent->parent->color = RED;
                
                // 처리 후 기준을 조상으로 올리는 루트 (반복)
                X = X->parent->parent;
            }
            else
            {
                if (X == X->parent->left)
                {
                    X = X->parent;
                    rotateRight(root, X);
                }

                X->parent->color = BLACK;
                X->parent->parent->color = RED;

                rotateLeft(root, X->parent->parent);
            }
        }
        // 반복문
        // X가 루트가 아니고, X의 부모가 색이 있는 경우
        // RED-RED 문제를 해결할 필요가 있는 경우에만 탐색
    }

    
    // root를 블랙으로 고정
    (*root)->color = BLACK;
}

/* 삭제 */
// 삭제하기
node    *removeNode(node **root, elementType data)
{
    // data : 우리가 지우고 싶은 값
    // target : data가 있는 노드
    // removed : target 대신 삭제할 노드
    // successor : removed의 자식
    node *removed = NULL;
    node *successor = NULL;
    node *target = NULL;
    
    // 삭제할 노드 찾기
    target = searchNode(*root, data);

    if (target == NULL)
        return NULL;
    
    /* 실제 제거될 노드 결정 */
    // 삭제할 노드 target이 끝에 있는 경우
    if (target->left == Nil || target->right == Nil)
        removed = target;
    // 삭제할 노드 target이 끝에 있지 않은 경우
    else
    {
        // 대신 삭제할 노드 removed를 찾는다. 
        removed = searchMinNode(target->right);
        // removed의 값을 target으로 옮긴다.
        target->data = removed->data;
    }

    // 우리가 지우고 싶은 값(target)은 직접 삭제되지 않는다.
    // 대신 다른 노드(removed)의 값을 가져와 덮어쓰고,
    // 그 removed 노드를 실제로 삭제한다.

    /* successor 찾고 연결하기 */
    // successor 찾기 1 : 대부분 상황
    if (removed->left == Nil)
        successor = removed->right;
    // successor 찾기 2 : removed == target 인 경우
    else if (removed->left != Nil)
        successor = removed->left;
    
    /* successor를 removed의 부모와 연결하기 */
    successor->parent = removed->parent;

    if (removed->parent == NULL)
        (*root) = successor;
    else if (removed == removed->parent->left)
        removed->parent->left = successor;
    else
        removed->parent->right = successor;

    /* RB 조건 검사 */
    // removed->color == black이면
    // removed 제거 후 RBT 상 각 경로의 black 갯수가 안 맞음
    if (removed->color == BLACK)
        rebuildAfterRemove(root, successor);
    
    return removed;
}

void    rebuildAfterRemove(node **root, node *successor)
{
    node *sibling = NULL;

    while (successor->parent != NULL && successor->color == BLACK)
    {
        if (successor == successor->parent->left)
        {
            // successor의 형제(sibiling)를 설정
            sibling = successor->parent->right;

            // sibiling == RED : 정렬 작업
            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateLeft(root, successor->parent);
            }
            // sibiling == BLACK
            else
            {
                // sibiling의 자식들이 모두 BLACK이면, sibling <= RED
                if (sibling->left->color == BLACK &&
                    sibling->right->color == BLACK)
                {
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else
                {
                    // sibling의 왼쪽 자식 == Red면
                    if (sibling->left->color == RED)
                    {
                        sibling->left->color = BLACK;
                        sibling->color = RED;

                        rotateRight(root, sibling);
                        sibling = successor->parent->right;
                    }
                    // sibling의 오른쪽 자식 == Red면
                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(root, successor->parent);
                    successor = (*root);
                }
            }
        }
        else
        {

        }
    }
}


void    printTree(node *node, int depth, int blackcount);
