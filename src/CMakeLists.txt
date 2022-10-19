set(LIBARY_SOURCES
cstring/cstring_utils.c
data_struct/generic_memory_buffer.c
data_struct/pointer_array.c
data_struct/external_chaining_hashtable.c
data_struct/linear_probing_hashtable.c
hashing/fnv1a.c
hashing/sha256.c
linear_algebra/vector2D.c
linear_algebra/vector3D.c
)

set(LIBARY_HEADERS
base_utils/check.h
base_utils/logger.h
cstring/cstring_utils.h
data_struct/codegen.h
data_struct/generic_memory_buffer.h
data_struct/pointer_array.h
data_struct/external_chaining_hashtable.h
data_struct/linear_probing_hashtable.h
hashing/fnv1a.h
hashing/sha256.h
linear_algebra/vector2D.h
linear_algebra/vector3D.h
base_utils.h
cstring.h
data_struct.h
hashing.h
linear_algebra.h
)

add_library(${PROJECT_NAME} ${LIBARY_SOURCES} ${LIBARY_HEADERS})