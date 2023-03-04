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
                                                            {.key = "foo", .value = (var)&numbers[0]},
                                                            {.key = "bar", .value = (var)&numbers[1]},
                                                            {.key = "baz", .value = (var)&numbers[2]},
                                                            {.key = "quu", .value = (var)&numbers[3]},
                                                            {.key = "tkad", .value = (var)&numbers[4]},
                                                            {.key = "gkamq", .value = (var)&numbers[5]},
                                                            {.key = "oftzf", .value = (var)&numbers[6]},
                                                            {.key = "kpop", .value = (var)&numbers[7]},
                                                            {.key = "vbcvc", .value = (var)&numbers[8]},
                                                            {.key = "fgiu", .value = (var)&numbers[9]},
                                                            {.key = "klui", .value = (var)&numbers[10]},
                                                            {.key = "weqdf", .value = (var)&numbers[11]},
                                                            {.key = "opgfz", .value = (var)&numbers[12]},
                                                            {.key = "sekjk", .value = (var)&numbers[13]},
                                                            {.key = "jkuwa", .value = (var)&numbers[14]},
                                                            {.key = "lökla", .value = (var)&numbers[15]},
                                                            {.key = "poiza", .value = (var)&numbers[16]},
                                                            {.key = "uisza", .value = (var)&numbers[17]},
                                                            {.key = "vysaa", .value = (var)&numbers[18]},
                                                            {.key = "sdada", .value = (var)&numbers[19]},
                                                        };
    linear_probing_hashtable_init_table(&table);
    linear_probing_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < 20; i++)
        linear_probing_hashtable_insert_entry(&entries[i], &table);   
    linear_probing_hashtable_print_table(&table);
    printf("value at foo: %i\n", *(int*)linear_probing_hashtable_look_up_entry("foo", &table)->value);
    linear_probing_hashtable_free_entries(&table);   
}

void seperate_chaining_hashtable_example()
{
    printf("External chaining hashtable\n");
    seperate_chaining_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    seperate_chaining_hashtable_entry_t entries [] =    {   
                                                            {.key = "foo", .value = (var)&numbers[0]},
                                                            {.key = "bar", .value = (var)&numbers[1]},
                                                            {.key = "baz", .value = (var)&numbers[2]},
                                                            {.key = "quu", .value = (var)&numbers[3]},
                                                            {.key = "tkad", .value = (var)&numbers[4]},
                                                            {.key = "gkamq", .value = (var)&numbers[5]},
                                                            {.key = "oftzf", .value = (var)&numbers[6]},
                                                            {.key = "kpop", .value = (var)&numbers[7]},
                                                            {.key = "vbcvc", .value = (var*)&numbers[8]},
                                                            {.key = "fgiu", .value = (var)&numbers[9]},
                                                            {.key = "klui", .value = (var)&numbers[10]},
                                                            {.key = "weqdf", .value = (var)&numbers[11]},
                                                            {.key = "opgfz", .value = (var)&numbers[12]},
                                                            {.key = "sekjk", .value = (var)&numbers[13]},
                                                            {.key = "jkuwa", .value = (var)&numbers[14]},
                                                            {.key = "lökla", .value = (var)&numbers[15]},
                                                            {.key = "poiza", .value = (var)&numbers[16]},
                                                            {.key = "uisza", .value = (var)&numbers[17]},
                                                            {.key = "vysaa", .value = (var)&numbers[18]},
                                                            {.key = "sdada", .value = (var)&numbers[19]},
                                                        };
    seperate_chaining_hashtable_init_table(&table);
    seperate_chaining_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < sizeof(entries) / sizeof(*entries); i++)
        seperate_chaining_hashtable_insert_entry(&entries[i], &table);
    seperate_chaining_hashtable_print_table(&table);
    printf("value at foo: %i\n", *(int*)seperate_chaining_hashtable_lookup_entry("foo", &table)->value);
    seperate_chaining_hashtable_free_entries(&table);
}

void quadratic_probing_hashtable_example()
{
    printf("quadratic probing hashtable\n");
    quadratic_probing_hashtable_t table;
    int numbers[] = {10, 5, 6, 2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
    quadratic_probing_hashtable_entry_t entries [] =    {   
                                                            {.key = "foo", .value = (var)&numbers[0]},
                                                            {.key = "bar", .value = (var)&numbers[1]},
                                                            {.key = "baz", .value = (var)&numbers[2]},
                                                            {.key = "quu", .value = (var)&numbers[3]},
                                                            {.key = "tkad", .value = (var)&numbers[4]},
                                                            {.key = "gkamq", .value = (var)&numbers[5]},
                                                            {.key = "oftzf", .value = (var)&numbers[6]},
                                                            {.key = "kpop", .value = (var)&numbers[7]},
                                                            {.key = "vbcvc", .value = (var)&numbers[8]},
                                                            {.key = "fgiu", .value = (var)&numbers[9]},
                                                            {.key = "klui", .value = (var)&numbers[10]},
                                                            {.key = "weqdf", .value = (var)&numbers[11]},
                                                            {.key = "opgfz", .value = (var)&numbers[12]},
                                                            {.key = "sekjk", .value = (var)&numbers[13]},
                                                            {.key = "jkuwa", .value = (var)&numbers[14]},
                                                            {.key = "lökla", .value = (var)&numbers[15]},
                                                            {.key = "poiza", .value = (var)&numbers[16]},
                                                            {.key = "uisza", .value = (var)&numbers[17]},
                                                            {.key = "vysaa", .value = (var)&numbers[18]},
                                                            {.key = "sdada", .value = (var)&numbers[19]},
                                                        };
    quadratic_probing_hashtable_init_table(&table);
    quadratic_probing_hashtable_set_print_function(&table, printInt);
    for (size_t i = 0; i < 20; i++)
        quadratic_probing_hashtable_insert_entry(&entries[i], &table);   
    quadratic_probing_hashtable_print_table(&table);
    printf("value at foo: %i\n", *(int*)quadratic_probing_hashtable_look_up_entry("foo", &table)->value);
    quadratic_probing_hashtable_free_entries(&table);
}