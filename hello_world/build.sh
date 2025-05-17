#!/usr/bin/env bash

rm -r build || true
mkdir build/
# rm -r main.dSYM/ || true

# debug
g++ -ggdb -o build/main main.cpp

# release
# g++ -O2 -DNDEBUG -o main main.cpp
