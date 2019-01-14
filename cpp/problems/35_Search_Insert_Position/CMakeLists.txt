cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(SearchInsertPosition solution.cpp)
target_link_libraries(SearchInsertPosition Catch2::Catch2)