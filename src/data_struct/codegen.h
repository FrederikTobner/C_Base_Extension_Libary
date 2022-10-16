#ifndef DATA_STRUCTURES_CODE_GENERATION_H
#define DATA_STRUCTURES_CODE_GENERATION_H

#define MAX(a,b) \
(((a)>(b)) ? (a) : (b))

#define MIN(a,b) \
(((a)<(b)) ? (a) : (b))

#define GEN_DYNARRAY_TYPE(TYPE)                     \
typedef struct                                      \
{                                                   \
size_t size;                                        \
size_t used;                                        \
TYPE *data;                                         \
}TYPE##_dynarray;

#define GEN_DYNARRAY_FUNCTIONS(TYPE)                \
bool TYPE##_da_init(TYPE##_dynarray *da,            \
size_t init_size,                                   \
size_t init_used)                                   \
{                                                   \
assert(init_size >= init_used);                     \
init_size = MAX(init_size, MIN_ARRAY_SIZE);         \
da->data =                                          \
checked_malloc(init_size, *da->data);               \
da->size = (da->data) ? init_size : 0;              \
da->used = (da->data) ? init_used : 0;              \
return !!da->data;                                  \
}                                                   \
                                                    \
void TYPE##_da_dealloc(TYPE##_dynarray *da)         \
{                                                   \
free(da->data);                                     \
da->data = 0;                                       \
da->size = da->used = 0;                            \
}                                                   \
                                                    \
bool TYPE##_da_resize(TYPE##_dynarray *da,          \
size_t new_size)                                    \
{                                                   \
size_t alloc_size =                                 \
MAX(new_size, MIN_ARRAY_SIZE);                      \
TYPE *new_data =                                    \
checked_realloc(da->data,                           \
alloc_size, *da->data);                             \
if (!new_data) return false;                        \
da->data = new_data;                                \
da->size = alloc_size;                              \
da->used = MIN(da->used, new_size);                 \
return true;                                        \
}                                                   \
                                                    \
bool TYPE##_da_append(TYPE##_dynarray *da,          \
 TYPE val)                                          \
{                                                   \
    if (da->used == da->size)                       \
    {                                               \
        if (at_max_len(da->size, *da->data))        \
        return false;                               \
        size_t new_size =                           \
        capped_dbl(da->size, *da->data);            \
        int resize_success =                        \
        TYPE##_da_resize(da, new_size);             \
        if (!resize_success)                        \
        return false;                               \
    }                                               \
        da->data[da->used++] = val;                 \
        return true;                                \
}

#define GEN_DYNARRAY_PROTOTYPES(TYPE)               \
bool TYPE##_da_init   (TYPE##_dynarray *da,         \
size_t init_size,                                   \
size_t init_used);                                  \
void TYPE##_da_dealloc(TYPE##_dynarray *da);        \
bool TYPE##_da_resize (TYPE##_dynarray *da,         \
size_t new_size);                                   \
bool TYPE##_da_append (TYPE##_dynarray *da,         \
TYPE val);

#endif