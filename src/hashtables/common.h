#ifndef HASHTABLES_COMMON_H
#define HASHTABLES_COMMON_H

#include <stdlib.h>

#define MAX_KEY_LENGTH (1024)

#define GROWTH_FACTOR (2)

#define TABLE_GROWTH_TRIGGER_VALUE (0.75)

#define TABLE_INIT_SIZE (8)

#define SIZE_CHECK_USING_TYPE(n,type) \
((SIZE_MAX / sizeof(type)) >= (n))

#define CHECKED_MALLOC_USING_TYPE(n,type) \
(SIZE_CHECK_USING_TYPE((n),(type)) ? \
malloc((n) * sizeof(type)) : 0)

#endif