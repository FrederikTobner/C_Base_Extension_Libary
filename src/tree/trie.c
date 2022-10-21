#include "trie.h"

#include <assert.h>
#include <stdlib.h>

int trie_add_child(trie_node_t * parent, trie_node_t * child)
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

void trie_free(trie_node_t * node)
{
    if(!node)
        return;
    if(node->children)
    {
        for (size_t i = 0; i < node->children->used; i++)
            trie_free(((trie_node_t *)pointer_array_at(node->children, i)));  
        free(node->children);
    } 
}

trie_node_t * trie_child_at(trie_node_t * node, size_t index)
{
    assert(node->children->used >= index);
    if(!node || !node->children)
        return NULL;
    return pointer_array_at(node->children, index);
}
