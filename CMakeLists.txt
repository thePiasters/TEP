cmake_minimum_required(VERSION 3.17)
project(Lista3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lista3 main.cpp CNodeStatic.cpp CNodeStatic.h CTreeStatic.cpp CTreeStatic.h CNodeDynamic.cpp CNodeDynamic.h CTreeDynamic.cpp CTreeDynamic.h)