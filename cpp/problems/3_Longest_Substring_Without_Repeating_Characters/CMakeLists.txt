cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(LongestSubstringWithout solution.cpp)

target_link_libraries(LongestSubstringWithout  Catch2::Catch2)