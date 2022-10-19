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

#define generic_memory_buffer_get(buffer,i) \
(void *)((buffer)->data + (i) * (buffer)->obj_size)

#define generic_memory_buffer_at_as(buffer,i,type) \
*(type *)generic_memory_buffer_get(buffer, i)

int generic_memory_buffer_append(generic_memory_buffer_t * buffer, void *val) ;

void generic_memory_buffer_dealloc(generic_memory_buffer_t * buffer);

int generic_memory_buffer_init(generic_memory_buffer_t * buffer, size_t obj_size);

int generic_memory_buffer_resize(generic_memory_buffer_t * buffer, size_t new_size);

#endif