cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)


add_executable(untitled1
        main.cpp
        CMySmartPointer.cpp
        CMySmartPointer.h
        CRefCounter.cpp
        CRefCounter.h
        CTab.cpp
        CTab.h
        CTable.h
        CTable.cpp
        Base.cpp
        Base.h
        Derived1.cpp
        Derived1.h)