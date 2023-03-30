cmake_minimum_required(VERSION 3.22)
project(labb2)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb2 main.cpp data_generation.cpp data_generation.h sorting_utils.cpp sorting_utils.h sorting_algorithms.cpp sorting_algorithms.h timing_utils.cpp timing_utils.h data_reporting.cpp data_reporting.h)
