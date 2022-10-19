#include "data_struct.h"

#include <stdio.h>

static void pointer_array_example();
static void generic_memory_buffer_example();
static void external_chaining_hashtable_example();

int main(int argc, char const ** argv)
{    
    pointer_array_example();
    generic_memory_buffer_example();
    external_chaining_hashtable_example();  
    return 0;
}

static void printInt(void * value)
{
    printf("%i", *(int*)value);
}

static void external_chaining_hashtable_example()
{
    external_chaining_hashtable_t table;
    int numbers[] = {10, 5, 6,  2, 3, 8, 7, 1, 11, 4, 74, 49, 23, 21, 34, 98, 12, 46, 54, 77};
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
    printf("value at foo: %i", *(int*)external_chaining_hashtable_lookup_entry("foo\n", &table)->value);
    external_chaining_hashtable_free_table(&table);
    external_chaining_hashtable_free_table(&table);
}

static void pointer_array_example()
{
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

static void generic_memory_buffer_example()
{
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


