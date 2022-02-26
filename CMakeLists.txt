cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/ordered_array_set/ordered_array_set.c
        libs/data_structures/vector/vector.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix_test.c
        libs/data_structures/matrix/matrix_task.c
        libs/data_structures/matrix/test_task.c)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)