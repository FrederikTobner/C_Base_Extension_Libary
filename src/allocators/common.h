#ifndef ALLOCATORS_COMMON_H
#define ALLOCATORS_COMMON_H

#include <stddef.h>

// Machine word size. Depending on the architecture
typedef void* word_t;

size_t determine_alignment(size_t n) 
{
    return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

#endif