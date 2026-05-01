#include <iostream>

// use of anonymous namespace to limit the scope of the functions to this file;
// similar to prefixing the functions with 'static'
namespace {

auto read_int() -> int {
  std::cout << "Enter an integer: ";
  int num{};
  std::cin >> num;
  return num;
}

// the constexpr allows the funtion to be evaluated at compile time if called
// with a constant expression, even though in this example it's evaluated at
// runtime as the integer input is not known at compile time
auto constexpr compute_is_even(int num) -> bool { return (num % 2 == 0); }

}  // namespace

auto main() -> int {
  int const num = {read_int()};
  bool const is_even = {compute_is_even(num)};
  if (is_even) {
    std::cout << "Got integer: " << num << ", which is even";
  } else {
    std::cout << "Got integer: " << num << ", which is not even";
  }
  return 0;
}
