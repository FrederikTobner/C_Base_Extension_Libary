#ifndef TREE_TRIE_H
#define TREE_TRIE_H

#include "../data_struct/pointer_array.h"

typedef struct
{
char character;
pointer_array_t * children;
}trie_node_t;

int trie_add_child(trie_node_t * parent, trie_node_t * child);

void trie_free(trie_node_t * node);

trie_node_t * trie_child_at(trie_node_t * node, size_t index);

#endif