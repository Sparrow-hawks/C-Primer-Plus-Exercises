// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  2

#include <iostream>
#include <array>

const unsigned int arraySize = 101;

int main(void) {

  std::array<long double, arraySize> factorials {{1.0, 1.0, 0.0}};

  for (unsigned int i = 2; i < arraySize; ++i) {
    factorials.at(i) = i * factorials.at(i - 1);
  }

  for (unsigned int i = 0; i < arraySize; ++i) {
    std::cout << i << "! = " << factorials[i] << std::endl;
  }
  return 0;
}
