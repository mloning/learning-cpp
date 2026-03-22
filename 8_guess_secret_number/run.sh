#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

clang --version

# build
rm -r build || true
mkdir build/
clang++ \
  -std=c++17 \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -lfmt \
  -Wall \
  -Wcast-align \
  -Wconversion \
  -Weffc++ \
  -Werror \
  -Wextra \
  -Wno-unused \
  -Wno-unused-parameter \
  -Wnon-virtual-dtor \
  -Wold-style-cast \
  -Woverloaded-virtual \
  -Wpointer-arith \
  -Wshadow \
  -Wsign-conversion \
  -Wundef \
  -pedantic-errors \
  -ggdb \
  -o build/main \
  main.cpp

# run
./build/main
