set(EXAMPLE_SOURCES
datastructure_examples.c
main.c
)

set(EXAMPLE_HEADERS
datastructure_examples.h
)

add_executable(${PROJECT_NAME}Example ${EXAMPLE_HEADERS} ${EXAMPLE_SOURCES})

target_link_libraries(${PROJECT_NAME}Example ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}Example PUBLIC ../src)