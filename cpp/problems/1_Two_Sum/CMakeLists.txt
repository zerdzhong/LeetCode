cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(Two_Sum solution.cpp)

target_link_libraries(Two_Sum Catch2::Catch2)