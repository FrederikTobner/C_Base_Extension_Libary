#include "pointer_array.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "common_macros.h"
#include "../core/memory.h"

int pointer_array_init(pointer_array_t *pointerArray)
{ 
    if(!pointerArray)
        return -1;
    pointerArray->data = CHECKED_MALLOC_USING_TYPE(MIN_ARRAY_SIZE, *pointerArray->data); 
    pointerArray->size = (pointerArray->data) ? MIN_ARRAY_SIZE : 0; 
    pointerArray->used = 0; 
    return !pointerArray->data; 
}

void pointer_array_dealloc(pointer_array_t * pointerArray)
{ 
    if(!pointerArray)
        return;
    delete(pointerArray->data);
    pointerArray->size = pointerArray->used = 0;
    pointerArray->data = NULL; 
}

int pointer_array_resize(pointer_array_t  * pointerArray, size_t new_size)
{ 
    if(!pointerArray)
        return -1;
    assert(new_size >= pointerArray->used);
    size_t alloc_size = MAX(new_size, MIN_ARRAY_SIZE); 
    void ** new_data = CHECKED_REALLOC_USING_TYPE(pointerArray->data, alloc_size, *pointerArray->data); 
    if (!new_data) 
        return -1; 
    pointerArray->data = new_data; 
    pointerArray->size = alloc_size; 
    pointerArray->used = MIN(pointerArray->used, new_size); 
    return 0; 
}

int pointer_array_append(pointer_array_t * pointerArray, void *value) 
{ 
    if(!pointerArray)
        return -1;
    if (pointerArray->used == pointerArray->size) 
    {
        if (AT_MAX_LENGTH_USING_TYPE(pointerArray->size, *pointerArray->data)) 
            return -1; 
        size_t new_size = CAPPED_DPL_SIZE_USING_TYPE(pointerArray->size, *pointerArray->data); 
        if ( pointer_array_resize(pointerArray, new_size)) return -1; 
    } 
    pointerArray->data[pointerArray->used++] = value; 
    return 0; 
}

void * pointer_array_at(pointer_array_t * pointerArray, size_t index)
{
    if(!pointerArray)
        return NULL;
    if(index >= pointerArray->used)
        return NULL;
    return pointerArray->data[index];
}
