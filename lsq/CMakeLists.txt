cmake_minimum_required(VERSION 3.26)
project(lsq)

set(CMAKE_CXX_STANDARD 17)

add_executable(lsq main.cpp
        LinkedList.cpp
        LinkedList.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h)
