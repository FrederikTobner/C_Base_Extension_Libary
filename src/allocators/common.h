#ifndef ALLOCATORS_COMMON_H
#define ALLOCATORS_COMMON_H

#include <stddef.h>

#include "../core/var.h"

size_t determine_alignment(size_t n) 
{
    return (n + sizeof(var) - 1) & ~(sizeof(var) - 1);
}

#endif