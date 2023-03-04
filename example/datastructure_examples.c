#include "datastructure_examples.h"

#include <stdio.h>

#include "data_struct.h"

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
    generic_memory_buffer_append(&buffer, (var)&val_1);
    generic_memory_buffer_append(&buffer, (var)&val_2);
    generic_memory_buffer_append(&buffer, (var)&val_3);
    for (size_t i = 0; i < 3; i++)
        printf("%i\n", generic_memory_buffer_at_as(&buffer, i, int));
    generic_memory_buffer_dealloc(&buffer);
}