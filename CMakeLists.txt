cmake_minimum_required(VERSION 3.16)
project(Polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(Polymorphism main.cpp DynamicArray.hpp DynamicArrayImplementation.hpp LinkedList.hpp LinkedListImplementation.hpp Utils.cpp Utils.hpp)