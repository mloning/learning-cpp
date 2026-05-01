#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

clang --version

# build
rm -r build || true
cmake -S . -B build/ -G "Ninja"
cmake --build build/

# run
./build/main
