#include <iostream>

// use of anonymous namespace to limit the scope of the functions to this file;
// similar to prefixing the functions with 'static'
namespace {

auto accumulate(int num) {
  static int sum{0};  // initialized once at the start of the program
  sum += num;
  return sum;
}

}  // namespace

auto main() -> int {
  std::cout << accumulate(4) << '\n';
  std::cout << accumulate(3) << '\n';
  std::cout << accumulate(2) << '\n';
  std::cout << accumulate(1) << '\n';

  return 0;
}
