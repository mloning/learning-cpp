#include <sys/types.h>

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "random.h"

namespace {

const uint min_num{1};
const uint max_num{100};

auto read_guess() -> uint {
  uint guess{};
  while (true) {
    std::cin >> guess;

    if (std ::cin.fail()) {
      // handling end of input gracefully
      if (std::cin.eof()) {
        std::cout << "End of input detected. Exiting." << "\n";
        std::exit(0);
      }

      // reset std::cin
      std::cin.clear();
      // clear bad input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      // TODO overflows are also handled under this case; it would be better to
      // handle them with the same message to enter a number between 1 and 100
      std::cout << "Invalid input; please enter a number: ";
    } else if (guess < min_num || guess > max_num) {
      // check number is within limits
      std::cout << "Invalid number; please enter a number between " << min_num
                << " and " << max_num << ": ";

    } else {
      break;
    }
  }
  return guess;
}
}  // namespace

auto main() -> int {
  const uint n_tries{7};

  const uint secret_num{Random::get<uint>(min_num, max_num)};

  std::cout << "Let's play a game: I'm thinking of a number between " << min_num
            << " and " << max_num << "; you have " << n_tries
            << " tries to guess what it is!" << "\n";

  uint guess{};
  for (uint i{1}; i <= n_tries; i++) {
    std::cout << "Guess: " << i << "/" << n_tries << ": ";
    guess = read_guess();
    assert(guess >= min_num && guess <= max_num);
    // std::cout << "Got: " << guess << ". ";
    if (guess < secret_num) {
      std::cout << "Too low!" << "\n";
    } else if (guess > secret_num) {
      std::cout << "Too high!" << "\n";
    } else {
      std::cout << "Correct! You win!" << "\n";
      return 0;
    }
  }
  std::cout << "You loose! The secret number was: " << secret_num;
  return 0;
}
