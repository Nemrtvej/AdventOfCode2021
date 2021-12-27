cmake_minimum_required(VERSION 3.21)
project(AdventOfCode2021)

set(CMAKE_CXX_STANDARD 23)

add_executable(AdventOfCode2021 src/Day04/main.cpp src/Day04/Solver.cpp src/Day04/Solver.h src/Day04/Bingo.cpp src/Day04/Bingo.h src/Day04/Parser.cpp src/Day04/Parser.h src/Day04/ParsedInput.cpp src/Day04/ParsedInput.h src/Day04/BingoField.cpp src/Day04/BingoField.h src/Day04/BingoNumber.cpp src/Day04/BingoNumber.h)
