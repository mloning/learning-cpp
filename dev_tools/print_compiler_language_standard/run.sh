#!/usr/bin/env bash

rm -r build || true
mkdir build/

cmd="g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror"

# debug
$cmd -ggdb -o build/main main.cpp && ./build/main
