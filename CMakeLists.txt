cmake_minimum_required(VERSION 3.22)
project(CPP7_MLP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP7_MLP
        src/main.cpp src/Matrix/Matrix.cpp src/Matrix/Matrix.hpp src/MLP.cpp src/MLP.hpp
        src/Graph/layer.h src/Graph/layer.cpp src/Graph/graph.h src/Graph/graph_realisation.cpp src/Graph/neuron.cpp src/Graph/neuron.h src/control/Control.cpp src/control/Control.hpp)
