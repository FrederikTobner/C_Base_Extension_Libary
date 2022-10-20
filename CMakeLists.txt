cmake_minimum_required(VERSION 3.16)

project(C_Basic_Extension_Libary VERSION 0.1.0)

set(C_STANDARD 99)
set(C_STANDARD_REQUIRED TRUE)

add_subdirectory(src)

add_subdirectory(example)

enable_testing()

add_subdirectory(test)