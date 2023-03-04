#include "pointer_tree.h"

#include <assert.h>
#include <stdlib.h>

#include "../core/memory.h"
#include "../core/var.h"

int pointer_tree_node_add_child(pointer_tree_node_t * parent, pointer_tree_node_t * child)
{
    if(!parent || !child)
        return -1;
    if(!parent->children)
    {
        parent->children = new(pointer_array_t);
        if(!parent->children)
            return -1;
        pointer_array_init(parent->children);
    }
    return pointer_array_append(parent->children, (var)child);
}

void pointer_tree_node_free(pointer_tree_node_t * node)
{
    if(!node)
        return;
    if(node->children)
    {
        for (size_t i = 0; i < node->children->used; i++)
            pointer_tree_node_free(((pointer_tree_node_t *)pointer_array_at(node->children, i)));
        pointer_array_dealloc(node->children);
        delete(node->children);
    } 
}

pointer_tree_node_t * pointer_tree_node_new()
{
    pointer_tree_node_t * node = new(pointer_tree_node_t);
    if(!node)
        return NULL;
    node->children = NULL;
    node->value = NULL;
    return node;
}

void pointer_tree_node_destory(pointer_tree_node_t ** node)
{
    if(!*node)
        return;
    delete(*node);
    *node = NULL;
}

pointer_tree_node_t * pointer_tree_node_child_at(pointer_tree_node_t * node, size_t index)
{
    assert(node->children->used >= index);
    if(!node || !node->children)
        return NULL;
    return pointer_array_at(node->children, index);
}
