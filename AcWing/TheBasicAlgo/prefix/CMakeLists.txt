cmake_minimum_required(VERSION 3.24)
project(prefix)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cc)
add_executable(matrix matrix.cc)
add_executable(diff diff.cc)
add_executable(matrix_diff matrix_diff.cc)
