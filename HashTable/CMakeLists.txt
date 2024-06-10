cmake_minimum_required(VERSION 3.27)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp
        LinkedList.h
        LinkedList.cpp
        HashTable.cpp
        HashTable.h)
