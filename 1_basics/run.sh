#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

# build
rm -r build || true
mkdir build/

g++ -v -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -ggdb -o build/main main.cpp

# run
./build/main
