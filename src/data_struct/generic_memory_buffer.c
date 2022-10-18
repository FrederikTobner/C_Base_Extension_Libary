#include "generic_memory_buffer.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "common_macros.h"

bool generic_memory_buffer_append(generic_memory_buffer_t * gmb, void *val) 
{ 
    if (gmb->used == gmb->size) 
    { 
        if (AT_MAX_LENGTH_USING_SIZE(gmb->size, gmb->obj_size)) 
            return false; 
        size_t new_size = CAPPED_DPL_USING_SIZE(gmb->size, gmb->obj_size); 
        int resize_success = generic_memory_buffer_resize(gmb, new_size); 
        if (!resize_success) 
            return false; 
    } 
    memcpy(gmb->data + gmb->used * gmb->obj_size,val, gmb->obj_size); 
    gmb->used++; 
    return true;
}

void generic_memory_buffer_dealloc(generic_memory_buffer_t * gmb) 
{
    free(gmb->data); 
    gmb->data = 0; 
    gmb->size = gmb->used = 0; 
}

bool generic_memory_buffer_init(generic_memory_buffer_t * gmb, size_t init_size, size_t init_used, size_t obj_size)
{
    assert(init_size >= init_used); 
    init_size = MAX(init_size, MIN_ARRAY_SIZE); 
    gmb->data = CHECKED_MALLOC_USING_SIZE(init_size, obj_size); 
    gmb->size = (gmb->data) ? init_size : 0;
    gmb->used = (gmb->data) ? init_used : 0;
    gmb->obj_size = obj_size; 
    return !!gmb->data;
}

bool generic_memory_buffer_resize(generic_memory_buffer_t * gmb, size_t new_size) 
{ 
    size_t alloc_size = MAX(new_size, MIN_ARRAY_SIZE); 
    char * new_data = CHECKED_REALLOC_USING_SIZE(gmb->data, alloc_size, gmb->obj_size); 
    if (!new_data) return false; 
    gmb->data = new_data; 
    gmb->size = alloc_size; 
    gmb->used = MIN(gmb->used, new_size); 
    return true; 
}
