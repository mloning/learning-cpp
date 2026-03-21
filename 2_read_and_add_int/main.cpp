#include "io.h"

auto main() -> int {
  int const a{readNumber()};  // NOLINT(readability-identifier-length)
  int const b{readNumber()};  // NOLINT(readability-identifier-length)
  writeAnswer(a + b);
  return 0;
}
