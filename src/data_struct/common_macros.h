#ifndef DATA_STRUCTURES_COMMON_H
#define DATA_STRUCTURES_COMMON_H

#define MIN(a,b) \
(((a)<(b)) ? (a) : (b))

#define MAX(a,b) \
(((a)>(b)) ? (a) : (b))

#define MIN_ARRAY_SIZE (1)

#define MAX_ARRAY_LENGTH_USING_TYPE(type) \
(SIZE_MAX / sizeof(type))

#define AT_MAX_LENGTH_USING_TYPE(n,type) \
((n) == MAX_ARRAY_LENGTH_USING_TYPE(type))

#define SIZE_CHECK_USING_TYPE(n,type) \
((SIZE_MAX / sizeof(type)) >= (n))

#define CHECKED_MALLOC_USING_TYPE(n,type) \
(SIZE_CHECK_USING_TYPE((n),(type)) ? \
malloc((n) * sizeof(type)) : 0)

#define CHECKED_REALLOC_USING_TYPE(p,n,type) \
(SIZE_CHECK_USING_TYPE((n),(type)) ? realloc((p), (n) * sizeof(type)) : 0)

#define CAPPED_DPL_SIZE_USING_TYPE(n,type) \
 (((n) < MAX_ARRAY_LENGTH_USING_TYPE(type) / 2) \
? (2 * (n)) : MAX_ARRAY_LENGTH_USING_TYPE(type))

#define SIZE_CHECK_USING_SIZE(n,obj_size) \
 ((SIZE_MAX / (obj_size)) >= (n))
 
#define CHECKED_MALLOC_USING_SIZE(n,obj_size) \
(SIZE_CHECK_USING_SIZE((n),(obj_size)) ? \
 malloc((n) * (obj_size)) : 0)

#define CHECKED_REALLOC_USING_SIZE(p,n,obj_size) (SIZE_CHECK_USING_SIZE((n),(obj_size)) ? realloc((p), (n) * (obj_size)) : 0) 

#define MAX_ARRAY_LENGTH_USING_SIZE(obj_size) \
(SIZE_MAX / obj_size) 

#define AT_MAX_LENGTH_USING_SIZE(n,obj_size) \
((n) == MAX_ARRAY_LENGTH_USING_SIZE(obj_size)) 

#define CAPPED_DPL_USING_SIZE(n,obj_size) \
(((n) < MAX_ARRAY_LENGTH_USING_SIZE(obj_size) / 2) \
? (2 * (n)) : MAX_ARRAY_LENGTH_USING_SIZE(obj_size))

#endif