#include "linear_allocator.h"

#include <stdlib.h>

#include "common.h"

#define ALLOCATOR_INIT_SIZE (1024u)

#define ALLOCATOR_GROWTH_FACTOR (2u)

static int linear_allocator_resize();

linear_allocator_t * linear_allocator_new()
{
    linear_allocator_t * allocator = malloc(sizeof(linear_allocator_t));
    if(!allocator)
        return NULL;
    allocator->memory = malloc(sizeof(ALLOCATOR_INIT_SIZE));
    if(!allocator->memory)
    {
        free(allocator);
        return NULL;
    }
    allocator->allocatedBytes = ALLOCATOR_INIT_SIZE;
    allocator->usedBytes = 0;
    return allocator;
}

void * linear_allocator_malloc(linear_allocator_t * allocator, size_t numberOfBytes)
{
    size_t allignedSize = determine_alignment(numberOfBytes);
    if(allocator->allocatedBytes - allocator->usedBytes < numberOfBytes)
        if(linear_allocator_resize)
            return NULL;
    allocator->usedBytes += allignedSize;
    return allocator->memory + allocator->usedBytes - allignedSize;
}

void linear_allocator_reset(linear_allocator_t * allocator)
{
    allocator->usedBytes = 0;
}

void linear_allocator_destroy(linear_allocator_t ** allocator)
{
    if(!*allocator)
        return;
    free((*allocator)->memory);
    free(*allocator);
    *allocator = NULL;
}

static int linear_allocator_resize(linear_allocator_t * allocator)
{
    char * newBlock = realloc(allocator->memory, allocator->allocatedBytes * ALLOCATOR_GROWTH_FACTOR);
    if(!newBlock)
        return -1;
    allocator->memory = newBlock;
}