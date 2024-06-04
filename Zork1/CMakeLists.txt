cmake_minimum_required(VERSION 3.27)
project(Zork1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug)
include_directories(build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug)

add_executable(Zork1
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/moc_homew.cpp
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/moc_mainwindow.cpp
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/moc_predefs.h
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ui_homew.h
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ui_mainwindow.h
        character.cpp
        character.h
        controller.cpp
        controller.h
        entity.cpp
        entity.h
        inventory.cpp
        inventory.h
        item.cpp
        item.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        room.cpp
        room.h
        model.h
        model.cpp)
