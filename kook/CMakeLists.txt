# CMakeList.txt : CMake project for kook, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (kook "main.cpp" "lexer.hpp" "lexer.cpp" "parser.hpp" "parser.cpp" "opcodes.hpp" "interpreter.hpp" "interpreter.cpp" "includes.hpp")

# TODO: Add tests and install targets if needed.
