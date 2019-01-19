cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(RegularExpressionMatch solution.cpp)
target_link_libraries(RegularExpressionMatch Catch2::Catch2)