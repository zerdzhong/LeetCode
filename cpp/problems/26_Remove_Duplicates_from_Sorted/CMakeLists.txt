cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(Remove_Duplicates_from_Sorted solution.cpp)
target_link_libraries(Remove_Duplicates_from_Sorted Catch2::Catch2)