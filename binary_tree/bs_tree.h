#ifndef BS_TREE_H
# define BS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct  s_node
{
    elementType     data;
    struct s_node   *left;
    struct s_node   *right;
}   t_node;

t_node  *create_node(elementType data);
void    destroy_node(t_node *node);
void    destroy_tree(t_node *tree);

t_node  *search_node(t_node *tree, elementType target);
void    insert_node(t_node *tree, t_node *child);
t_node  *remove_node(t_node *tree, t_node *parent, elementType target);
t_node  *search_minnode(t_node *node);
void    print_tree(t_node *tree);

#endif