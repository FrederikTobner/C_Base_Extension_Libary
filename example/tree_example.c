#include "tree_example.h"

#include <stdio.h>

#include "tree.h"

void pointer_tree_example()
{
    printf("Pointer Tree\n");
    int numbers[] = {10, 5, 6, 2, 12};
    pointer_tree_node_t treeRoot = {.value = &numbers[0]};
    pointer_tree_node_t firstChild = {.value = &numbers[1]};
    pointer_tree_node_t secondChild = {.value = &numbers[2]};
    pointer_tree_node_t firstChildChild = {.value = &numbers[3]};
    pointer_tree_node_t secondChildChild = {.value = &numbers[4]};
    pointer_tree_add_child(&treeRoot, &firstChild);
    pointer_tree_add_child(&treeRoot, &secondChild);
    pointer_tree_add_child(&firstChild, &firstChildChild);
    pointer_tree_add_child(&secondChild, &secondChildChild);
    printf("%i\n", *(int*)((pointer_tree_node_t *)pointer_tree_child_at(&treeRoot, 0)->value));
    printf("%i\n", *(int*)((pointer_tree_node_t *)pointer_tree_child_at(&treeRoot, 1)->value));
    printf("%i\n", *(int*)((pointer_tree_node_t *)pointer_tree_child_at(&firstChild, 0)->value));
    printf("%i\n", *(int*)((pointer_tree_node_t *)pointer_tree_child_at(&secondChild, 0)->value));
    pointer_tree_free(&treeRoot);
}

void trie_example()
{
    printf("Trie\n");
    trie_node_t root = {.character = 'M'};
    trie_node_t firstChild = {.character = 'I'};
    trie_node_t secondChild = {.character = 'O'};
    trie_add_child(&root, &firstChild);
    trie_add_child(&root, &secondChild);
    printf("%c\n", trie_child_at(&root, 0)->character);
    printf("%c\n", trie_child_at(&root, 1)->character);
    trie_free(&root);
}