cmake_minimum_required(VERSION 3.31)

project(
  guess_secret_number
  VERSION 1.0.0
  DESCRIPTION "Guess the secret number game"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)

target_compile_options(main PRIVATE
  -Wall
  -Wcast-align
  -Wconversion
  -Weffc++
  -Werror
  -Wextra
  -Wno-unused
  -Wno-unused-parameter
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Woverloaded-virtual
  -Wpointer-arith
  -Wshadow
  -Wsign-conversion
  -Wundef
  -ggdb
  -pedantic-errors
)
