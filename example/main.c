#include "allocators_examples.h"
#include "base_utils_examples.h"
#include "datastructure_examples.h"
#include "hashtable_examples.h"
#include "tree_examples.h"

int main(int argc, char const ** argv)
{   
    seperate_chaining_hashtable_example();
    generic_memory_buffer_example();
    linear_probing_hashtable_example();
    pointer_array_example();
    pointer_tree_example();
    trie_example();
    quadratic_probing_hashtable_example();
    linear_allocator_example();
    checkv_example();
    return 0;   
}