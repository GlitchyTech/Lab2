cmake_minimum_required(VERSION 3.16)
project(Polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(Polymorphism main.cpp DynamicArray.hpp DynamicArrayImplementation.hpp List.hpp ListImplementation.hpp Utils.cpp Utils.hpp ISequence.hpp ArraySequence.hpp ArraySequenceImplementation.hpp ListSequence.hpp ListSequenceImplementation.hpp StringVectorImplementation.hpp StringVector.hpp StringList.hpp StringListImplementation.hpp)