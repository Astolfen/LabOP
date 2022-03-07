cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/ordered_array_set/ordered_array_set.c)

add_library(str string/string_.c string/string_.h
        string/task/task1.h string/task/task2.h
        string/task/task3.h
        #string/task/task4.h
        #string/task/task5.h
        #string/task/task6.h
        #string/task/task7.h
        #string/task/task8.h
        #string/task/task9.h
        #string/task/task10.h
        #string/task/task11.h
        #string/task/task12.h
        #string/task/task13.h
        #string/task/task14.h
        #string/task/task15.h
        )

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)
target_link_libraries(untitled str)