#include <iostream>

namespace {

// single template type
template <typename T>
auto add(T a, T b) -> T {  // NOLINT(readability-identifier-length)
  return a + b;
}

// multiple template types
template <typename U, typename T>
auto sub(U a, T b) -> auto {  // NOLINT(readability-identifier-length)
  return a - b;
}

// single template type with fixed type
template <typename T>
auto mult(T a, int b) -> T {  // NOLINT(readability-identifier-length)
  return a * b;
}

}  // namespace

auto main() -> int {
  // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  std::cout << add(2, 3) << '\n';
  std::cout << add(1.2, 3.4) << '\n';
  std::cout << mult(2, 3) << '\n';
  std::cout << mult(1.2, 3) << '\n';
  std::cout << sub(3, 2) << '\n';
  std::cout << sub(3.5, 2) << '\n';
  std::cout << sub(4, 1.5) << '\n';
  // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

  return 0;
}
