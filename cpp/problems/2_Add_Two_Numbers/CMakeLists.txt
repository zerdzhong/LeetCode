cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(AddTwoNumbers solution.cpp)

target_link_libraries(AddTwoNumbers Catch2::Catch2)