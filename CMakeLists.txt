cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)