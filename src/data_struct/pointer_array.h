#ifndef DATA_STRUCTURES_POINTER_ARRAY_H
#define DATA_STRUCTURES_POINTER_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct { 
size_t size; 
size_t used; 
void ** data; 
}pointer_array_t;

bool pointer_array_init(pointer_array_t * pointerArray, size_t init_size, size_t init_used);

void pointer_array_dealloc(pointer_array_t * pointerArray);

bool pointer_array_resize(pointer_array_t * pointerArray, size_t new_size);

bool pointer_array_append(pointer_array_t * pointerArray, void *val);

void * pointer_array_at(pointer_array_t * pointerArray, size_t index);

#endif