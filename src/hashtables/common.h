#ifndef HASHTABLES_COMMON_H
#define HASHTABLES_COMMON_H

#include <stdlib.h>

/// The maximum length of the key of a hashtable entry
#define MAX_KEY_LENGTH (1024)

/// The growth factor of a hashtable
#define GROWTH_FACTOR (2)

/// The growth trigger value of a hashtables
#define TABLE_GROWTH_TRIGGER_VALUE (0.75)

/// The initial size of a hashtables
#define TABLE_INIT_SIZE (8)

/// Size check using a type (used for the checked malloc)
#define SIZE_CHECK_USING_TYPE(n,type) \
((SIZE_MAX / sizeof(type)) >= (n))

/// @brief Checked malloc
/// @details Treats a overflow parameters when malloc was called like a usual allocation error
#define CHECKED_MALLOC_USING_TYPE(n,type) \
(SIZE_CHECK_USING_TYPE((n),(type)) ? \
malloc((n) * sizeof(type)) : 0)

#endif