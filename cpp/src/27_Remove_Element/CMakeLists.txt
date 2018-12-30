cmake_minimum_required(VERSION 3.13)
project(RemoveElement)

add_executable(RemoveElement solution.cpp)
target_link_libraries(RemoveElement Catch2::Catch2)