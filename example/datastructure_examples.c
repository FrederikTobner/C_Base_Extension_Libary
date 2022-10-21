#include "datastructure_examples.h"

#include <stdio.h>

#include "data_struct.h"

void printInt(void * value)
{
    printf("%i", *(int*)value);
}

void linear_probing_hashtable_example()
{
    printf("Linear probing hashtable\n");
    linear_probing_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    linear_probing_hashtable_entry_t entries [] =  {   
                                                            {.key = "foo", .value = (void*)&numbers[0]},
                                                            {.key = "bar", .value = (void*)&numbers[1]},
                                                            {.key = "baz", .value = (void*)&numbers[2]},
                                                            {.key = "quu", .value = (void*)&numbers[3]},
                                                            {.key = "tkad", .value = (void*)&numbers[4]},
                                                            {.key = "gkamq", .value = (void*)&numbers[5]},
                                                            {.key = "oftzf", .value = (void*)&numbers[6]},
                                                            {.key = "kpop", .value = (void*)&numbers[7]},
                                                            {.key = "vbcvc", .value = (void*)&numbers[8]},
                                                            {.key = "fgiu", .value = (void*)&numbers[9]},
                                                            {.key = "klui", .value = (void*)&numbers[10]},
                                                            {.key = "weqdf", .value = (void*)&numbers[11]},
                                                            {.key = "opgfz", .value = (void*)&numbers[12]},
                                                            {.key = "sekjk", .value = (void*)&numbers[13]},
                                                            {.key = "jkuwa", .value = (void*)&numbers[14]},
                                                            {.key = "lökla", .value = (void*)&numbers[15]},
                                                            {.key = "poiza", .value = (void*)&numbers[16]},
                                                            {.key = "uisza", .value = (void*)&numbers[17]},
                                                            {.key = "vysaa", .value = (void*)&numbers[18]},
                                                            {.key = "sdada", .value = (void*)&numbers[19]},
                                                        };
    linear_probing_hashtable_init_table(&table);
    linear_probing_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < 20; i++)
        linear_probing_hashtable_insert_entry(&entries[i], &table);   
    linear_probing_hashtable_print_table(&table);
     printf("value at foo: %i\n", *(int*)linear_probing_hashtable_look_up_entry("foo", &table)->value);
    linear_probing_hashtable_free_table(&table);   
}

void external_chaining_hashtable_example()
{
    printf("External chaining hashtable\n");
    external_chaining_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    external_chaining_hashtable_entry_t entries [] =    {   
                                                            {.key = "foo", .value = (void*)&numbers[0]},
                                                            {.key = "bar", .value = (void*)&numbers[1]},
                                                            {.key = "baz", .value = (void*)&numbers[2]},
                                                            {.key = "quu", .value = (void*)&numbers[3]},
                                                            {.key = "tkad", .value = (void*)&numbers[4]},
                                                            {.key = "gkamq", .value = (void*)&numbers[5]},
                                                            {.key = "oftzf", .value = (void*)&numbers[6]},
                                                            {.key = "kpop", .value = (void*)&numbers[7]},
                                                            {.key = "vbcvc", .value = (void*)&numbers[8]},
                                                            {.key = "fgiu", .value = (void*)&numbers[9]},
                                                            {.key = "klui", .value = (void*)&numbers[10]},
                                                            {.key = "weqdf", .value = (void*)&numbers[11]},
                                                            {.key = "opgfz", .value = (void*)&numbers[12]},
                                                            {.key = "sekjk", .value = (void*)&numbers[13]},
                                                            {.key = "jkuwa", .value = (void*)&numbers[14]},
                                                            {.key = "lökla", .value = (void*)&numbers[15]},
                                                            {.key = "poiza", .value = (void*)&numbers[16]},
                                                            {.key = "uisza", .value = (void*)&numbers[17]},
                                                            {.key = "vysaa", .value = (void*)&numbers[18]},
                                                            {.key = "sdada", .value = (void*)&numbers[19]},
                                                        };
    external_chaining_hashtable_init_table(&table);
    external_chaining_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < sizeof(entries) / sizeof(*entries); i++)
        external_chaining_hashtable_insert_entry(&entries[i], &table);
    external_chaining_hashtable_print_table(&table);
    printf("value at foo: %i\n", *(int*)external_chaining_hashtable_lookup_entry("foo", &table)->value);
    external_chaining_hashtable_free_table(&table);
}

void pointer_array_example()
{
    printf("Pointer Array\n");
    pointer_array_t pa;
    if(pointer_array_init(&pa))
        return;
    int i = 10;
    char c = '!';
    double d = 1.1;
    if(pointer_array_append(&pa, &i))
        return;
    if(pointer_array_append(&pa, &c))
        return;
    if(pointer_array_append(&pa, &d))
        return;
    printf("%i\n", *((int * )pointer_array_at(&pa, 0)));
    printf("%c\n", *((char * )pointer_array_at(&pa, 1)));
    printf("%g\n", *((double * )pointer_array_at(&pa, 2)));
    pointer_array_dealloc(&pa);
}

void generic_memory_buffer_example()
{
    printf("Generic memory buffer\n");
    generic_memory_buffer_t buffer;
    generic_memory_buffer_init(&buffer, sizeof(int));
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