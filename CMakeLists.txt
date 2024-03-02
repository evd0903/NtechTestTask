cmake_minimum_required(VERSION 3.12)

project(TransposeMatrixAsync)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransposeMatrixAsync src/main.cpp src/Worker.h src/Worker.cpp tests/tests.h tests/test_runner.h)
