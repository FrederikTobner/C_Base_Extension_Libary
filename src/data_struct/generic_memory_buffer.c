#include "generic_memory_buffer.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "common_macros.h"

int generic_memory_buffer_append(generic_memory_buffer_t * buffer, void *value) 
{ 
    if(!buffer)
        return -1;
    if (buffer->used == buffer->size) 
    { 
        if (AT_MAX_LENGTH_USING_SIZE(buffer->size, buffer->obj_size)) 
            return -1; 
        size_t new_size = CAPPED_DPL_USING_SIZE(buffer->size, buffer->obj_size); 
        if (generic_memory_buffer_resize(buffer, new_size)) 
            return -1; 
    } 
    memcpy(buffer->data + buffer->used * buffer->obj_size, value, buffer->obj_size); 
    buffer->used++; 
    return 0;
}

void generic_memory_buffer_dealloc(generic_memory_buffer_t * buffer) 
{
    if(!buffer)
        return;
    free(buffer->data); 
    buffer->data = 0; 
    buffer->size = buffer->used = 0; 
}

int generic_memory_buffer_init(generic_memory_buffer_t * buffer, size_t obj_size)
{
    if(!buffer)
        return -1;
    buffer->data = CHECKED_MALLOC_USING_SIZE(MIN_ARRAY_SIZE, obj_size); 
    buffer->size = (buffer->data) ? MIN_ARRAY_SIZE : 0;
    buffer->used = 0;
    buffer->obj_size = obj_size; 
    return !buffer->data;
}

int generic_memory_buffer_resize(generic_memory_buffer_t * buffer, size_t new_size) 
{ 
    if(!buffer)
        return -1;
    size_t alloc_size = MAX(new_size, MIN_ARRAY_SIZE); 
    char * new_data = CHECKED_REALLOC_USING_SIZE(buffer->data, alloc_size, buffer->obj_size); 
    if (!new_data) return -1; 
    buffer->data = new_data; 
    buffer->size = alloc_size; 
    buffer->used = MIN(buffer->used, new_size); 
    return 0; 
}
