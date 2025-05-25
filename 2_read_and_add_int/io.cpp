#include "io.h"

#include <iostream>

int readNumber() {
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  return x;
}

void writeAnswer(int num) { std::cout << "The sum is: " << num; }
