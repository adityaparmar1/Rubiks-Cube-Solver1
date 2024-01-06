cmake_minimum_required(VERSION 3.26)
project(Rubiks_Cube_Solver1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rubiks_Cube_Solver1 main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube3dArray.h
)
