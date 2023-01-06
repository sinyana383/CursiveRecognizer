cmake_minimum_required(VERSION 3.22)
project(CPP7_MLP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP7_MLP
        src/main.cpp src/Matrix.cpp src/Matrix.hpp src/MLP.cpp src/MLP.hpp)
