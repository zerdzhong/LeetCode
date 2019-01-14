cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(SearchRotatedSortedArray solution.cpp)
target_link_libraries(SearchRotatedSortedArray Catch2::Catch2)