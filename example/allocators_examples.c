#include "allocators_examples.h"

#include <stdio.h>

#include "allocators.h"

void linear_allocator_example()
{
    printf("Linear Allocator\n");
    linear_allocator_t * allocator = linear_allocator_new();
    if(!allocator)
        return;
    int * i = LINEAR_ALLOCATOR_MALLOC(allocator, int);
    *i = 123;
    double * d = LINEAR_ALLOCATOR_MALLOC(allocator, double);
    *d = 1.2;
    char * c = LINEAR_ALLOCATOR_MALLOC(allocator, char);
    *c = '\t';
    printf("%i%c%g\n", *i, *c, *d);
    linear_allocator_destroy(&allocator);
}