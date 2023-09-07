#include "bs_tree.h"

void    print_search_result(int search_target, t_node *node)
{
    if (node->data == search_target)
        printf("found : %d \n", node->data);
    else
        printf("not found : %d \n", node->data);
}

int main()
{
    // 노드 생성
    t_node *tree = create_node(123);
    t_node *node = NULL;

    // 트리에 노드 추가
    int num[10] = {22, 9918, 424, 17, 3, 98, 34, 760, 317, 1};
    for (int i = 0; i < 10; i++)
        insert_node(tree, create_node(num[i]));

    // 원소 검색 후 출력
    int search_target = 17;
    node = search_node(tree, search_target);
    print_search_result(search_target, node);

    // 트리 전체 출력
    print_tree(tree);
    printf(" \n");

    // 특정 노드 삭제
    int remove_target = 98;
    printf("removing %d...\n", remove_target);
    node = remove_node(tree, NULL, remove_target);
    destroy_node(node);

    // 트리 전체 출력
    print_tree(tree);
    printf(" \n");

    // 새 노드 삽입
    int insert_number = 111;
    printf("insert %d...\n", insert_number);
    insert_node(tree, create_node(insert_number));

    // 트리 전체 출력
    print_tree(tree);
    printf(" \n");

    // 트리 소멸
    destroy_tree(tree);
}