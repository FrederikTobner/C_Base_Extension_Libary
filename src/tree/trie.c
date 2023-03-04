#include "trie.h"

#include <assert.h>
#include <stdlib.h>

#include "../core/memory.h"
#include "../core/var.h"

int trie_init_trie(trie_t * trie)
{
    if(!trie)
        return -1;
    if(!trie->root)
    {
        trie->root = new(trie_node_t);
        if(!trie->root)
            return -1;
         trie->root->children = new(pointer_array_t);
        if(!trie->root->children)
            return -1;
        if(pointer_array_init(trie->root->children))
            return -1;
    }   
    return 0;
}

trie_t * trie_new()
{
    trie_t * table = new(trie_t);
    if(!table)
        return NULL;
    trie_init_trie(table);
    return table;
}

void trie_destory(trie_t ** trie)
{
    if(!*trie)
        return;
    trie_free_from_node((*trie)->root);
    delete(*trie);
    *trie = NULL;
}

int trie_add_word_to_trie(trie_t * trie, char const * word)
{
    trie_node_t * currentNode = trie->root;    
    for (; *word; currentNode = trie_get_child_of_node_by_character(currentNode, *word), word++)
        if(trie_get_child_of_node_by_character(currentNode, *word) == NULL)
            if(trie_add_child_to_node_with_character(currentNode, *word))
                return -1;
    return 0;
}

int trie_add_child_to_node(trie_node_t * parent, trie_node_t * child)
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

int trie_add_child_to_node_with_character(trie_node_t * parent, char const character)
{
    if(!parent)
        return -1;
    trie_node_t * child = new(trie_node_t);
    child->character = character;
    child->children = NULL;
    if(!child)
        return -1;
    return trie_add_child_to_node(parent, child);
}

void trie_free_from_node(trie_node_t * node)
{
    if(!node)
        return;
    if(node->children)
    {
        for (size_t i = 0; i < node->children->used; i++)
            trie_free_from_node(((trie_node_t *)pointer_array_at(node->children, i)));  
        free(node->children);
    } 
}

trie_node_t * trie_get_child_of_node_by_index(trie_node_t * node, size_t index)
{    
    if(!node || !node->children)
        return NULL;
    assert(node->children->used >= index);
    return pointer_array_at(node->children, index);
}

trie_node_t * trie_get_child_of_node_by_character(trie_node_t * node, char const character)
{    
    if(!node || !node->children)
        return NULL;
    trie_node_t * currentNode;
    size_t i;
    for (i = 0, currentNode = pointer_array_at(node->children, 0); i < node->children->used; i++, currentNode = (trie_node_t *)pointer_array_at(node->children, i))
        if(currentNode->character == character)
            return currentNode;
    return NULL;
}
