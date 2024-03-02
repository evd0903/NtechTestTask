cmake_minimum_required(VERSION 3.12)

project(TransposeMatrixAsync)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransposeMatrixAsync 
    src/main.cpp 
    src/Worker.h 
    src/Worker.cpp
)

enable_testing()

add_executable(ci_tests
    tests/tests.h
    tests/tests.cpp
    tests/test_runner.h
)
