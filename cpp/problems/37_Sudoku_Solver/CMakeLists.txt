cmake_minimum_required(VERSION 3.13)
project(SudokuSolver)

add_executable(SudokuSolver solution.cpp)
target_link_libraries(SudokuSolver Catch2::Catch2)