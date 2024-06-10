cmake_minimum_required(VERSION 3.27)
project(Orbital)

set(CMAKE_CXX_STANDARD 17)

add_executable(Orbital main.cpp
        sublink.cpp
        sublink.h
        Orbital.cpp
        Orbital.h)
