#ifndef MEMORY_LINEAR_ALLOCATOR_H
#define MEMORY_LINEAR_ALLOCATOR_H

#include <stddef.h>
#include <stdint.h>

#define LINEAR_ALLOCATOR_MALLOC(allocator, type) linear_allocator_malloc(allocator, sizeof(type));

typedef struct
{
size_t allocatedBytes;
size_t usedBytes;
uint8_t * memory;
}linear_allocator_t;

linear_allocator_t * linear_allocator_new();

void * linear_allocator_malloc(linear_allocator_t * allocator, size_t numberOfBytes);

void linear_allocator_reset(linear_allocator_t * allocator);

void linear_allocator_destroy(linear_allocator_t ** allocator);

#endif