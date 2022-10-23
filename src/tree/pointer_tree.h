#ifndef TREE_POINTER_TREE_H
#define TREE_POINTER_TREE_H

#include <stddef.h>
#include "../data_struct/pointer_array.h"

typedef struct
{
void * value;
pointer_array_t * children;
}pointer_tree_node_t;

typedef struct
{
pointer_tree_node_t * root;
}pointer_tree_t;

int pointer_tree_add_child(pointer_tree_node_t * parent, pointer_tree_node_t * child);

void pointer_tree_free(pointer_tree_node_t * node);

pointer_tree_node_t * pointer_tree_child_at(pointer_tree_node_t * node, size_t index);

#endif