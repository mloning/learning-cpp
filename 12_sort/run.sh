#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

# build
rm -r build || true
mkdir build/

# clang++ seems to be mostly interchangeable with g++
clang++ -v -std=c++17 \
  -pedantic-errors \
  -Wall \
  -Weffc++ \
  -Wextra \
  -Wconversion \
  -Wsign-conversion \
  -Wshadow \
  -Werror \
  -Wnon-virtual-dtor \
  -Wold-style-cast \
  -Wcast-align \
  -Woverloaded-virtual \
  -Wpointer-arith \
  -Wundef \
  -Wno-unused \
  -Wno-unused-parameter \
  -ggdb \
  -o build/main \
  main.cpp

# run
./build/main
