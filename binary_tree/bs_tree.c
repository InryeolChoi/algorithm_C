#include "bs_tree.h"

t_node  *create_node(elementType data)
{
    t_node *newnode;

    newnode = (t_node *)malloc(sizeof(t_node));
    if (!newnode)
        return (NULL);
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    return (newnode);
}

void    destroy_node(t_node *node)
{
    free(node);
}

void    destroy_tree(t_node *tree)
{
    if (tree->right != NULL)
        destroy_tree(tree->right);
    if (tree->left != NULL)
        destroy_tree(tree->left);
    tree->right = NULL;
    tree->left = NULL;
    destroy_node(tree);
}

t_node  *search_node(t_node *tree, elementType target)
{
    if (tree == NULL)
        return (NULL);
    
    if (tree->data == target)
        return (tree);
    else if (tree->data > target)
        return (search_node(tree->left, target));
    else
        return (search_node(tree->right, target));
}

void    insert_node(t_node *tree, t_node *child)
{
    if (tree->data < child->data)
    {
        if (tree->right == NULL)
            tree->right = child;
        else
            insert_node(tree->right, child);
    }
    else if (tree->data > child->data)
    {
        if (tree->left == NULL)
            tree->left = child;
        else
            insert_node(tree->left, child);
    }
}

t_node  *search_minnode(t_node *tree)
{
    if (tree == NULL)
        return (NULL);

    if (tree->left == NULL)
        return (tree);
    else
        return (search_minnode(tree->left));
}

t_node  *remove_node(t_node *tree, t_node *parent, elementType target)
{
    t_node  *removed;
    t_node  *minnode;
    t_node  *temp;

    if (tree == NULL)
        return (NULL);

    // 목표값보다 큰 경우
    if (tree->data > target)        
        removed = remove_node(tree->left, tree, target);
    
    // 목표값보다 작은 경우
    else if (tree->data < target)
        removed = remove_node(tree->right, tree, target);
    
    // 목표값인 경우
    else
    {
        removed = tree; // 돌려줄 주소 = 나무의 맨 위

        // 자식이 없는 경우
        if (tree->left == NULL && tree->right == NULL)
        {
            if (parent->left = tree)
                parent->left = NULL;
            else
                parent->right = NULL;
        }

        // 자식이 있는 경우
        else
        {
            // 자식이 둘 다 있는 경우
            if (tree->left != NULL && tree->right != NULL)
            {
                minnode = search_minnode(tree->right);
                minnode = remove_node(tree, NULL, minnode->data);
                tree->data = minnode->data;
            }

            // 자식이 한쪽만 있는 경우
            else
            {
                temp = NULL;
                if (tree->left != NULL)
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
    return (removed);
}

void    print_tree(t_node *node)
{
    if (node == NULL)
        return ;
    print_tree(node->left);
    printf("%d ", node->data);
    print_tree(node->right);
}