cmake_minimum_required(VERSION 3.15)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(TicTacToe main.cpp
        engine/handler/gameengine.cpp
        engine/handler/gameengine.h
        engine/globals/gamestate.h
        engine/view/viewmanager.cpp
        engine/view/viewmanager.h
        engine/objects/field.cpp
        engine/objects/field.h
        engine/globals/key.h
        engine/objects/coordinate.h
        engine/globals/token.h
        engine/objects/game.cpp
        engine/objects/game.h
        engine/objects/player.h)