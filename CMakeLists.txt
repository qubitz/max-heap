cmake_minimum_required(VERSION 3.0)
project(q2)

add_compile_options(-std=c++11)

add_executable(q2 q2.cpp
                  MaxHeap.cpp)