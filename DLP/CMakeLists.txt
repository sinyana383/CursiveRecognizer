cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp layer.cpp layer.h common.cpp common.h
        graph.h graph_realisation.cpp neuron.cpp neuron.h)
