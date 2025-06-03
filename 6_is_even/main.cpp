#include <iostream>

int read_int() {
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  return x;
}

// the constexpr allows the funtion to be evaluated at compile time if called
// with a constant expression, even though in this example it's evaluated at
// runtime as the integer input is not known at compile time
bool constexpr compute_is_even(int x) { return (x % 2 == 0); }

int main() {
  int x = {read_int()};
  bool is_even = {compute_is_even(x)};
  if (is_even) {
    std::cout << "Got integer: " << x << ", which is even";
  } else {
    std::cout << "Got integer: " << x << ", which is not even";
  }
  return 0;
}
