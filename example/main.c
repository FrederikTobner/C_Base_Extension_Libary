#include "data_struct.h"

#include <stdio.h>

static void pointer_array_example();
static void generic_memory_buffer_example();
static void external_chaining_hashtable_example();

int main(int argc, char const *argv[])
{    
    pointer_array_example();
    generic_memory_buffer_example();
    external_chaining_hashtable_example();  
    return 0;
}

static void external_chaining_hashtable_example()
{
    external_chaining_hashtable_t table;
    external_chaining_hashtable_entry_t entries [] =    {   
                                                            {.key = "Test", .value = 10},
                                                            {.key = "foo", .value = 5},
                                                            {.key = "bar", .value = 6},
                                                            {.key = "baz", .value = 2},
                                                            {.key = "quu", .value = 3},
                                                            {.key = "ghjg", .value = 8},
                                                            {.key = "oftzf", .value = 7},
                                                            {.key = "kpop", .value = 1},
                                                            {.key = "vbcvc", .value = 11},
                                                            {.key = "fgiu", .value = 4},
                                                            {.key = "klui", .value = 74},
                                                            {.key = "weqdf", .value = 49},
                                                            {.key = "opgfz", .value = 23},
                                                            {.key = "sekjk", .value = 21},
                                                            {.key = "jköwa", .value = 34},
                                                            {.key = "lökla", .value = 98},
                                                            {.key = "poiza", .value = 12},
                                                            {.key = "uisza", .value = 46},
                                                            {.key = "vysaa", .value = 54},
                                                            {.key = "sdada", .value = 57},
                                                        };
    external_chaining_hashtable_init_table(&table);
    for (size_t i = 0; i < sizeof(entries) / sizeof(*entries); i++)
        external_chaining_hashtable_insert_entry(&entries[i], &table);
    external_chaining_hashtable_print_table(&table);
}

static void pointer_array_example()
{
    pointer_array_t pa;
    if(!pointer_array_init(&pa, 10, 0))
        return;
    int i = 10;
    char c = '!';
    double d = 1.1;
    if(!pointer_array_append(&pa, &i))
        return;
    if(!pointer_array_append(&pa, &c))
        return;
    if(!pointer_array_append(&pa, &d))
        return;
    printf("%i\n", *((int * )pointer_array_at(&pa, 0)));
    printf("%c\n", *((char * )pointer_array_at(&pa, 1)));
    printf("%g\n", *((double * )pointer_array_at(&pa, 2)));
    pointer_array_dealloc(&pa);
}

static void generic_memory_buffer_example()
{
    generic_memory_buffer_t buffer;
    generic_memory_buffer_init(&buffer, 1, 0, sizeof(int));
    int val_1 = 1;
    int val_2 = 2;
    int val_3 = 3;
    generic_memory_buffer_append(&buffer, (void*)&val_1);
    generic_memory_buffer_append(&buffer, (void*)&val_2);
    generic_memory_buffer_append(&buffer, (void*)&val_3);
    for (size_t i = 0; i < 3; i++)
        printf("%i\n", generic_memory_buffer_at_as(&buffer, i, int));
    generic_memory_buffer_dealloc(&buffer);
}


