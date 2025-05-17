#!/usr/bin/env bash

rm -r build || true
mkdir build/

cmd="g++ -v -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror"

# debug
$cmd -ggdb -o build/main main.cpp

# release
# $cmd -O2 -DNDEBUG -o main main.cpp
