cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(Implement_strStr solution.cpp)
target_link_libraries(Implement_strStr Catch2::Catch2)