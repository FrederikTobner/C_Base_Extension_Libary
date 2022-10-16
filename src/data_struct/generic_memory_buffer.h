#ifndef DATA_STRUCTURES_GENERIC_MEMORY_BUFFER_H
#define DATA_STRUCTURES_GENERIC_MEMORY_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct { 
size_t size; 
size_t used;  
size_t obj_size; 
char * data; 
}generic_memory_buffer_t;

#define generic_memory_buffer_get(gmb,i) \
(void *)((gmb)->data + (i) * (gmb)->obj_size)

#define generic_memory_buffer_at_as(gmb,i,type) \
*(type *)generic_memory_buffer_get(gmb, i)

bool generic_memory_buffer_append(generic_memory_buffer_t * gmb, void *val) ;

void generic_memory_buffer_dealloc(generic_memory_buffer_t * gmb);

bool generic_memory_buffer_init(generic_memory_buffer_t * gmb, size_t init_size, size_t init_used, size_t obj_size);

bool generic_memory_buffer_resize(generic_memory_buffer_t * gmb, size_t new_size);

#endif