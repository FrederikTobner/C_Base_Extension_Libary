#ifndef DATA_STRUCTURES_POINTER_TREE_H
#define DATA_STRUCTURES_POINTER_TREE_H

#include <stddef.h>

typedef struct pointer_tree_node_t
{
void * value;
size_t usedCount;
size_t allocatedCount;
struct pointer_tree_node_t * children;
}pointer_tree_node_t;

int pointer_tree_add_child(pointer_tree_node_t * parent, pointer_tree_node_t * child);

void pointer_tree_free(pointer_tree_node_t * node);

pointer_tree_node_t * pointer_tree_child_at(pointer_tree_node_t * node, size_t index);

#endif