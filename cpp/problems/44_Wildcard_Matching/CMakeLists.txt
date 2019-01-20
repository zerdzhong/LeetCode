cmake_minimum_required(VERSION 3.13)
project(LeetCode)

add_executable(WildcardMatching solution.cpp)
target_link_libraries(WildcardMatching Catch2::Catch2)