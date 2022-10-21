#include "pointer_tree.h"

#include <assert.h>
#include <stdlib.h>

int pointer_tree_add_child(pointer_tree_node_t * parent, pointer_tree_node_t * child)
{
    if(!parent || !child)
        return -1;
    if(!parent->children)
    {
        parent->children = malloc(sizeof(pointer_array_t));
        if(!parent->children)
            return -1;
        pointer_array_init(parent->children);
    }
    return pointer_array_append(parent->children, (void*)child);
}

void pointer_tree_free(pointer_tree_node_t * node)
{
    if(!node)
        return;
    if(node->children)
    {
        for (size_t i = 0; i < node->children->used; i++)
            pointer_tree_free(((pointer_tree_node_t *)pointer_array_at(node->children, i)));
        pointer_array_dealloc(node->children);
        free(node->children);
    } 
}

pointer_tree_node_t * pointer_tree_child_at(pointer_tree_node_t * node, size_t index)
{
    assert(node->children->used >= index);
    if(!node || !node->children)
        return NULL;
    return pointer_array_at(node->children, index);
}
