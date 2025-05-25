#include <iostream>
#include <set>

double read_double() {
  std::cout << "Enter a double value: ";
  double x{};
  std::cin >> x;
  return x;
};

char read_operator() {
  std::set<char> operators = {'+', '-', '*', '/'};
  char x{};
  while (true) {
    std::cout << "Enter {";
    for (auto it = operators.begin(); it != operators.end(); ++it) {
      std::cout << *it;
      if (std::next(it) != operators.end()) {
        std::cout << ", ";
      }
    }
    std::cout << "}: ";
    std::cin >> x;
    if (operators.count(x)) {
      break;
    } else {
      std::cout << "Invalid operator. Please try again.\n";
    }
  }
  return x;
};

int main() {
  double a = {read_double()};
  double b = {read_double()};
  char op = {read_operator()};

  double result;
  if (op == '+')
    result = a + b;
  else if (op == '-')
    result = a - b;
  else if (op == '*')
    result = a * b;
  else if (op == '/')
    result = a / b;
  else {
    std::cout << "Invalid operator.";
    return 1;
  }

  std::cout << a << " " << op << " " << b << " = " << result;
  return 0;
}
