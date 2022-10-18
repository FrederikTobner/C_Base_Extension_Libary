#include "pointer_array.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "common_macros.h"

bool pointer_array_init(pointer_array_t *pointerArray, size_t init_size, size_t init_used)
{ 
    assert(init_size >= init_used); 
    init_size = MAX(init_size, MIN_ARRAY_SIZE); 
    pointerArray->data = CHECKED_MALLOC_USING_TYPE(init_size, *pointerArray->data); 
    pointerArray->size = (pointerArray->data) ? init_size : 0; 
    pointerArray->used = (pointerArray->data) ? init_used : 0; 
    return !!pointerArray->data; 
}

void pointer_array_dealloc(pointer_array_t * pointerArray)
{ 
    free(pointerArray->data); 
    pointerArray->data = 0; 
    pointerArray->size = 
    pointerArray->used = 0; 
}

bool pointer_array_resize(pointer_array_t  * pointerArray, size_t new_size)
{ 
    size_t alloc_size = MAX(new_size, MIN_ARRAY_SIZE); 
    void ** new_data = CHECKED_REALLOC_USING_TYPE(pointerArray->data, alloc_size, *pointerArray->data); 
    if (!new_data) 
        return false; 
    pointerArray->data = new_data; 
    pointerArray->size = alloc_size; 
    pointerArray->used = MIN(pointerArray->used, new_size); 
    return true; 
}

bool pointer_array_append(pointer_array_t * pointerArray, void *val) 
{ 
    if (pointerArray->used == pointerArray->size) 
    {
        if (AT_MAX_LENGTH_USING_TYPE(pointerArray->size, *pointerArray->data)) 
            return false; 
        size_t new_size = CAPPED_DPL_SIZE_USING_TYPE(pointerArray->size, *pointerArray->data); 
        int resize_success = pointer_array_resize(pointerArray, new_size); if (!resize_success) return false; 
    } 
    pointerArray->data[pointerArray->used++] = val; 
    return true; 
}

void * pointer_array_at(pointer_array_t * pointerArray, size_t index)
{
    if(index >= pointerArray->used)
        return NULL;
    return pointerArray->data[index];
}
