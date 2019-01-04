cmake_minimum_required(VERSION 3.13)
project(SearchRange)

add_executable(SearchRange solution.cpp)
target_link_libraries(SearchRange Catch2::Catch2)