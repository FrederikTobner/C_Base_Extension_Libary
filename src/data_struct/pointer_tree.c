#include "pointer_tree.h"

#include <assert.h>
#include <stdlib.h>

int pointer_tree_add_child(pointer_tree_node_t * parent, pointer_tree_node_t * child)
{
    if(!parent || !child)
        return -1;
    if(!parent->children)
    {
        if(!parent->children)
            return -1;
    }
}

void pointer_tree_free(pointer_tree_node_t * node)
{
    if(!node)
        return;
    if(node->children)
    {
        //TODO Make deallocation work
    }        
}

pointer_tree_node_t * pointer_tree_child_at(pointer_tree_node_t * node, size_t index)
{
    if(!node)
        return NULL;
}
