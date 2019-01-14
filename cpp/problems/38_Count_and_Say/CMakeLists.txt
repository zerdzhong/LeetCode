cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(CountAndSay solution.cpp)
target_link_libraries(CountAndSay Catch2::Catch2)