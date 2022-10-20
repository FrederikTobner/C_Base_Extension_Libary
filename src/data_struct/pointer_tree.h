#ifndef DATA_STRUCTURES_POINTER_TREE_H
#define DATA_STRUCTURES_POINTER_TREE_H

#include <stddef.h>

typedef struct pointer_tree_node_t
{
void * value;
size_t usedChildrenCount;
size_t allocatedChildsCount;
struct pointer_tree_node_t * nodes;
}pointer_tree_node_t;

typedef struct
{
    struct pointer_tree_node_t * rootNode;
    void (*printValue) (void* value);
}pointer_tree_t;

void pointer_tree_add_child(pointer_tree_node_t * node);

void pointer_tree_free_from_root(pointer_tree_node_t * node);

#endif