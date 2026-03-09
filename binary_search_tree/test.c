#include "binarySearchTree.h"

void printSearchResult(int target, BSTNode *result)
{
    if (result != NULL)
        printf("Found : %d \n", result->data);
    else
        printf("Not Found : %d\n", target);
}

int main()
{
    BSTNode *tree = createNode(123);
    BSTNode *node = NULL;

    int arr[10] = {22, 9918, 424, 17, 3, 98, 34, 760, 317, 1};

    for (int i = 0; i < 10; i++)
        insertNode(tree, createNode(arr[i]));

    int target[2] = {17, 117};
    for (int i = 0; i < 2; i++)
    {
        node = searchNode(tree, target[i]);
        printSearchResult(target[i], node);
    }

    InorderPrintTree(tree);
    printf("\n");

    printf("removing 98...\n");
    node = removeNode(tree, NULL, 98);
    destoryNode(node);

    InorderPrintTree(tree);
    printf("\n");

    printf("insert 111...\n");
    insertNode(tree, createNode(111));
    InorderPrintTree(tree);
    printf("\n");

    destoryTree(tree);
}