#include "hashtable_examples.h"

#include <stdio.h>

#include "hashtables.h"

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
    linear_probing_hashtable_free_entries(&table);   
}

void external_chaining_hashtable_example()
{
    printf("External chaining hashtable\n");
    seperate_chaining_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    seperate_chaining_hashtable_entry_t entries [] =    {   
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
    external_chaining_hashtable_free_entries(&table);
}

void quadratic_probing_hashtable_example()
{
    printf("quadratic probing hashtable\n");
    quadratic_probing_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    quadratic_probing_hashtable_entry_t entries [] =    {   
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
    quadratic_probing_hashtable_init_table(&table);
    quadratic_probing_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < 20; i++)
        quadratic_probing_hashtable_insert_entry(&entries[i], &table);   
    quadratic_probing_hashtable_print_table(&table);
    printf("value at foo: %i\n", *(int*)quadratic_probing_hashtable_look_up_entry("foo", &table)->value);
    quadratic_probing_hashtable_free_entries(&table);
}