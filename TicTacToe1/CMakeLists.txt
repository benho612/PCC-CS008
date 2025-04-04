cmake_minimum_required(VERSION 3.24.2)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe main.cpp TicTacToe/Game.cpp TicTacToe/GameLogic.cpp TicTacToe/Grid.cpp TicTacToe/Letter.cpp TicTacToe/Player.cpp gameInterface/Application.cpp gameInterface/Application.h gameInterface/Component.cpp gameInterface/Component.h HangMan/hangMan.cpp HangMan/hangMan.h HangMan/board.cpp HangMan/board.h HangMan/letterBank.cpp HangMan/letterBank.h HangMan/word.cpp HangMan/word.h FileIO.cpp FileIO.h)
