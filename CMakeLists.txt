cmake_minimum_required(VERSION 3.28)
project(Hamilton_and_Euler_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hamilton_and_Euler_project main.cpp
        Printer.h
        Printer.cpp
        Graph.h
        Graph.cpp
        Action.h
        Action.cpp
        Exporter.h
        Exporter.cpp
        Euler.h
        Euler.cpp
        Hamilton.h
        Hamilton.cpp
        InvalidDataException.h
        InvalidDataException.h
        InvalidDataException.cpp)
