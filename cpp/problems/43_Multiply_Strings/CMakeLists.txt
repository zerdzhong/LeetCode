cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(MultiplyStrings solution.cpp)
target_link_libraries(MultiplyStrings Catch2::Catch2)