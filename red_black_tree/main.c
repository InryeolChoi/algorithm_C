#include "redblacktree.h"

node    *Nil = NULL;

static void initNil(void)
{
    Nil = createnode(0);
    Nil->color = BLACK;
    Nil->left = Nil;
    Nil->right = Nil;
    Nil->parent = NULL;
}

static void destroyAll(node *root)
{
    if (root != NULL && root != Nil)
        destroytree(root);
    destroynode(Nil);
}

static void printMenu(void)
{
    printf("\n");
    printf("===== 레드블랙 트리 메뉴 =====\n");
    printf("1. 값 삽입\n");
    printf("2. 값 삭제\n");
    printf("3. 값 검색\n");
    printf("4. 트리 출력\n");
    printf("5. 종료\n");
    printf("메뉴를 선택하세요: ");
}

int main(void)
{
    node    *root;
    node    *found;
    node    *removed;
    node    *newnode;
    int     choice;
    int     value;

    root = NULL;
    initNil();

    while (1)
    {
        printMenu();
        if (scanf("%d", &choice) != 1)
        {
            printf("입력이 올바르지 않습니다.\n");
            break;
        }
        if (choice == 1)
        {
            printf("삽입할 값을 입력하세요: ");
            if (scanf("%d", &value) != 1)
            {
                printf("입력이 올바르지 않습니다.\n");
                break;
            }
            if (searchNode(root == NULL ? Nil : root, value) != NULL)
            {
                printf("%d은(는) 이미 존재합니다.\n", value);
                continue;
            }
            newnode = createnode(value);
            insertNode(&root, newnode);
            printf("%d을(를) 삽입했습니다.\n", value);
        }
        else if (choice == 2)
        {
            printf("삭제할 값을 입력하세요: ");
            if (scanf("%d", &value) != 1)
            {
                printf("입력이 올바르지 않습니다.\n");
                break;
            }
            if (root == NULL)
            {
                printf("트리가 비어 있습니다.\n");
                continue;
            }
            removed = removeNode(&root, value);
            if (removed == NULL)
                printf("%d을(를) 찾지 못했습니다.\n", value);
            else
            {
                printf("%d을(를) 삭제했습니다.\n", value);
                destroynode(removed);
                if (root == Nil)
                    root = NULL;
            }
        }
        else if (choice == 3)
        {
            printf("검색할 값을 입력하세요: ");
            if (scanf("%d", &value) != 1)
            {
                printf("입력이 올바르지 않습니다.\n");
                break;
            }
            found = searchNode(root == NULL ? Nil : root, value);
            if (found == NULL)
                printf("%d을(를) 찾지 못했습니다.\n", value);
            else
                printf("%d을(를) 찾았습니다.\n", found->data);
        }
        else if (choice == 4)
        {
            if (root == NULL)
                printf("트리가 비어 있습니다.\n");
            else
                printTree(root, 0, 0);
        }
        else if (choice == 5)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else
            printf("없는 메뉴입니다.\n");
    }

    destroyAll(root);
    return 0;
}
