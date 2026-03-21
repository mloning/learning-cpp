#include <cmath>
#include <iostream>
#include <iterator>
#include <set>

// use of anonymous namespace to limit the scope of the functions to this file;
// similar to prefixing the functions with 'static'
namespace {

auto read_double() -> double {
  std::cout << "Enter a double value: ";
  double num{};
  std::cin >> num;
  return num;
}

auto read_operator() -> char {
  std::set<char> operators = {'+', '-', '*', '/'};
  char operator_{};
  while (true) {
    std::cout << "Enter {";
    for (auto it = operators.begin(); it != operators.end(); ++it) {
      std::cout << *it;
      if (std::next(it) != operators.end()) {
        std::cout << ", ";
      }
    }
    std::cout << "}: ";
    std::cin >> operator_;
    if (operators.count(operator_) != 0U) {
      break;
    }
    std::cout << "Invalid operator. Please try again.\n";
  }
  return operator_;
}

auto main() -> int {
  double const num_a = {read_double()};
  double const num_b = {read_double()};
  char const operator_ = {read_operator()};

  double result = NAN;
  if (operator_ == '+')
    result = num_a + num_b;
  else if (operator_ == '-')
    result = num_a - num_b;
  else if (operator_ == '*')
    result = num_a * num_b;
  else if (operator_ == '/')
    result = num_a / num_b;
  else {
    std::cout << "Invalid operator.";
    return 1;
  }

  std::cout << num_a << " " << operator_ << " " << num_b << " = " << result;
  return 0;
}
}  // namespace
