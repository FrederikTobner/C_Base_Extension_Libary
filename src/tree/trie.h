#ifndef TREE_TRIE_H
#define TREE_TRIE_H

#include "../data_struct/pointer_array.h"

typedef struct
{
char character;
pointer_array_t * children;
}trie_node_t;

typedef struct
{
trie_node_t * root;
}trie_t;

int trie_add_child_to_node_with_character(trie_node_t * parent, char const character);

int trie_init_trie(trie_t * trie);

int trie_add_word_to_trie(trie_t * trie, char const * word);

int trie_add_child_to_node(trie_node_t * parent, trie_node_t * child);

void trie_free_from_node(trie_node_t * node);

trie_node_t * trie_get_child_of_node_by_index(trie_node_t * node, size_t index);

trie_node_t * trie_get_child_of_node_by_character(trie_node_t * node, char const character);

#endif