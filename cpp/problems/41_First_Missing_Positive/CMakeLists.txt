cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(FirstMissingPositive solution.cpp)
target_link_libraries(FirstMissingPositive Catch2::Catch2)