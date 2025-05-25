#include <iostream>

double read_height() {
  std::cout << "Enter the height of the tower in meters: ";
  double height{};
  std::cin >> height;
  return height;
};

double compute_distance_fallen(double seconds) {
  double gravity_constant{9.8};
  double dist = gravity_constant * seconds * seconds / 2.0;
  return dist;
}

int main() {
  double initial_height = {read_height()};
  for (int i = 0; i <= 5; ++i) {
    float seconds = static_cast<float>(i);
    double fallen = {compute_distance_fallen(seconds)};
    double height = {initial_height - fallen};
    if (height > 0.0) {
      std::cout << "At " << seconds
                << " seconds, the ball is at height: " << height
                << " meters.\n";
    } else {
      std::cout << "At " << seconds << " seconds, the ball is on the ground.";
      return 0;
    }
  }
  return 0;
}
