cmake_minimum_required(VERSION 3.21)
project(csescpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(csescpp main.cpp Maths/Base_difference_function.h Tricks/sort_compare_function.h Tricks/tmp.h)
