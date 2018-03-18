// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  2

#include <iostream>
#include <array>


int main(void) {
  size_t size {0};
  const size_t max_size {10};

  std::array<double, max_size> donations {};

  std::cout << "Enter donations. [10 or non digit value]: ";
  for (size_t i = 0; i < 10 && std::cin >> donations.at(i); ++i)
    ++size;

  double average = 0;
  for (auto it = donations.begin(); it != donations.end(); ++it)
    average += *it;
  average /= size;

  std::cout << "Average: " << average << std::endl;
  std::cout << "Values greater than average: ";

  for (double element : donations) {
    if (element > average)
      std::cout << element << ", ";
  }
  std::cout << "\b\b" << std::endl;

  return 0;
}
