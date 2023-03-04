#ifndef DATA_STRUCTURES_POINTER_ARRAY_H
#define DATA_STRUCTURES_POINTER_ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include "../core/var.h"

typedef struct { 
size_t size; 
size_t used; 
var * data; 
}pointer_array_t;

int pointer_array_init(pointer_array_t * pointerArray);

void pointer_array_dealloc(pointer_array_t * pointerArray);

int pointer_array_resize(pointer_array_t * pointerArray, size_t new_size);

int pointer_array_append(pointer_array_t * pointerArray, void *value);

void * pointer_array_at(pointer_array_t * pointerArray, size_t index);

#endif