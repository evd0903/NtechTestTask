cmake_minimum_required(VERSION 3.12)

project(TransposeMatrixAsync)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransposeMatrixAsync main.cpp Worker.h Worker.cpp)
