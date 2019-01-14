cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(ValidSudoku solution.cpp)
target_link_libraries(ValidSudoku Catch2::Catch2)