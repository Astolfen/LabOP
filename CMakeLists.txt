cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/ordered_array_set/ordered_array_set.c)

add_library(str string/string_.c string/string_.h
        string/task/task1.h)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)
target_link_libraries(untitled str)