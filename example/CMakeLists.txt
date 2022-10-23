set(EXAMPLE_SOURCES
allocators_examples.c
datastructure_examples.c
hashtable_examples.c
main.c
tree_examples.c
)

set(EXAMPLE_HEADERS
allocators_examples.h
datastructure_examples.h
hashtable_examples.h
tree_examples.h
)

add_executable(${PROJECT_NAME}Example ${EXAMPLE_HEADERS} ${EXAMPLE_SOURCES})

target_link_libraries(${PROJECT_NAME}Example ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}Example PUBLIC ../src)