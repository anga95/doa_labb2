cmake_minimum_required(VERSION 3.22)
project(labb2)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb2 main.cpp datagenerate.cpp datagenerate.h insertionsort.cpp sorting.h selectionsort.cpp quickSortRight.cpp sorting_utils.cpp sorting_utils.h sorting_algorithms.cpp sorting_algorithms.h)
