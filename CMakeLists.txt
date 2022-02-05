cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        libs/algorithms/array/array.c libs/algorithms/array/array.h
        libs/algorithms/algorithm.c libs/algorithms/algorithm.h
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/unordered_array_set/unordered_array_set.h
        libs/data_structures/ordered_array_set/ordered_array_set.c
        libs/data_structures/ordered_array_set/ordered_array_set.h
        libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)