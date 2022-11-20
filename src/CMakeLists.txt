set(LIBARY_SOURCES
allocators/linear_allocator.c
cstring/cstring_utils.c
data_struct/generic_memory_buffer.c
data_struct/pointer_array.c
data_struct/single_linked_list.c
hashing/elf.c
hashing/fnv1a.c
hashing/jenkins.c
hashing/sha256.c
hashtables/linear_probing_hashtable.c
hashtables/quadratic_probing_hashtable.c
hashtables/seperate_chaining_hashtable.c
linear_algebra/vector2D.c
linear_algebra/vector3D.c
tree/pointer_tree.c
tree/trie.c
)

set(LIBARY_HEADERS
allocators/linear_allocator.h
allocators/common.h
base_utils/check.h
base_utils/logger.h
cstring/cstring_utils.h
data_struct/codegen.h
data_struct/generic_memory_buffer.h
data_struct/pointer_array.h
data_struct/single_linked_list.h
hashing/elf.h
hashing/fnv1a.h
hashing/jenkins.h
hashing/sha256.h
hashtables/common.h
hashtables/linear_probing_hashtable.h
hashtables/quadratic_probing_hashtable.h
hashtables/seperate_chaining_hashtable.h
linear_algebra/vector2D.h
linear_algebra/vector3D.h
tree/pointer_tree.h
tree/trie.h
allocators.h
base_utils.h
cstring.h
data_struct.h
hashing.h
linear_algebra.h
tree.h
)

if( MSVC )  
add_compile_definitions(MSVC_VER)
endif()

add_library(${PROJECT_NAME} ${LIBARY_SOURCES} ${LIBARY_HEADERS})