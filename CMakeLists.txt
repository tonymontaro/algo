cmake_minimum_required(VERSION 3.21)
project(csescpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(csescpp main.cpp AtCoderLibrary/SCC_strongly_connected_components.h AtCoderLibrary/string.h AtCoderLibrary/segment_tree.h AtCoderLibrary/lazy_segment_tree.h AtCoderLibrary/mod_int.h Geometry/Rotate_Matrix_90_Degree.h ProblemAnalysis/Instructive/Geometry/Rotate_A_Vector_and_Translate_To_Origin.h)
