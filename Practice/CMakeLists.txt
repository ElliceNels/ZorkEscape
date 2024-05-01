cmake_minimum_required(VERSION 3.27)
project(Practice)

set(CMAKE_CXX_STANDARD 14)

include_directories("new zork")

add_executable(Practice
        "new zork/Character.cpp"
        "new zork/Character.h"
        "new zork/Command.cpp"
        "new zork/Command.h"
        "new zork/CommandWords.cpp"
        "new zork/CommandWords.h"
        "new zork/item.cpp"
        "new zork/item.h"
        "new zork/Parser.cpp"
        "new zork/Parser.h"
        "new zork/Room.cpp"
        "new zork/Room.h"
        "new zork/ZorkUL.cpp"
        "new zork/ZorkUL.h")
