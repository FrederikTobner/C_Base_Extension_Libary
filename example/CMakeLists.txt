add_executable(${PROJECT_NAME}Example main.c)

target_link_libraries(${PROJECT_NAME}Example ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}Example PUBLIC ../src)