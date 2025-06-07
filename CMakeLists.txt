cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Models/TicTacToe/TicTacToe.cpp
        Models/TicTacToe/TicTacToe.h
        Models/WinningPattern/WinningPattern.cpp
        Models/WinningPattern/WinningPattern.h
        Models/TicAI/TicAI.cpp
        Models/TicAI/TicAI.h
        Managers/TicTacToeGame/TicTacToeGame.cpp
        Managers/TicTacToeGame/TicTacToeGame.h)
