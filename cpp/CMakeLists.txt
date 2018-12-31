cmake_minimum_required(VERSION 3.13)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib3rd/Catch2)

add_subdirectory(problems/1_Two_Sum)
add_subdirectory(problems/26_Remove_Duplicates_from_Sorted)
add_subdirectory(problems/27_Remove_Element)
add_subdirectory(problems/28_Implement_strStr)

