cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(CombinationSum solution.cpp)
target_link_libraries(CombinationSum Catch2::Catch2)