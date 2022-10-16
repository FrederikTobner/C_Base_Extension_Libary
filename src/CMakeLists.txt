set(LIBARY_SOURCES
data_struct/generic_memory_buffer.c
data_struct/pointer_array.c
data_struct/external_chaining_hashtable.c
data_struct/linear_probing_hashtable.c
hashing/fnv1a.c
hashing/sha256.c
)

set(LIBARY_HEADERS
base_utils/check.h
base_utils/logger.h
data_struct/codegen.h
data_struct/generic_memory_buffer.h
data_struct/pointer_array.h
data_struct/external_chaining_hashtable.h
data_struct/linear_probing_hashtable.h
hashing/fnv1a.h
hashing/sha256.h
data_struct.h
hashing.h
base_utils.h
)

add_library(${PROJECT_NAME} ${LIBARY_SOURCES} ${LIBARY_HEADERS})