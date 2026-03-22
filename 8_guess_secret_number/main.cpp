#include <sys/types.h>

#include <iostream>

#include "random.h"

auto main() -> int {
  const uint n_tries{7};

  const uint min_num{1};
  const uint max_num{100};
  const uint secret_num{Random::get<uint>(min_num, max_num)};

  std::cout << "Let's play a game: I'm thinking of a number between " << min_num
            << " and " << max_num << "; you have " << n_tries
            << " tries to guess what it is!" << "\n";

  uint guess{};
  for (uint i{1}; i <= n_tries; i++) {
    std::cout << "Guess: " << i << "/" << n_tries << ": ";
    std::cin >> guess;
    // if (guess < secret_num) {
    //   std::cout << "Too low!" << "\n";
    //   } else if (guess > secret_num) {
    //     std::cout << "Too high!" << "\n";
    // } else {
    //   std::cout << "Correct! You win!" << "\n";
    //   return 0;
    // }
  }
  std::cout << "You loose! The secret number was: " << secret_num;
  return 0;
}
