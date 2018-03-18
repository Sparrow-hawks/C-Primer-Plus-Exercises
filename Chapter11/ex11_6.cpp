// Book:      C++ Primer Plus
// Chapter:   11
// Exercise:  6

#include <iostream>
#include <algorithm>
#include "stonewt_2.h"

int main() {
  const size_t SIZE = 6;

  StoneWT weights[SIZE] = {
    StoneWT(176.3698),
    StoneWT(121.2543),
    StoneWT(15, 6.0530),
  };

  for (size_t i = 3; i < SIZE; ++i) {
    double w;
    std::cout << "Enter weight in lbs: ";
    std::cin >> w;
    weights[i].setWeight(w);
  }

  size_t count = 0, index_min = 0, index_max = 0;
  StoneWT min = weights[0];
  StoneWT max = weights[0];
  StoneWT pat {11, 0.0};
  for (size_t i = 0; i < SIZE; ++i) {
    if (weights[i] < min) {
      min = weights[i];
      index_min = i;
    }
    if (weights[i] > max) {
      max = weights[i];
      index_max = i;
    }
    if (weights[i] <= pat) {
      ++count;
    }
  }

  std::cout << "Element with smallest weight: " << index_min << std::endl;
  std::cout << "Element with largest weight: " << index_max << std::endl;
  std::cout << "Element with weight <= 11 stones: " << count << std::endl;

  return 0;
}
