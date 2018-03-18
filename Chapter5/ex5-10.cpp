// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  10

#include <iostream>

int main(void) {
  unsigned int rowNumber {0};

  std::cout << "Podaj liczbę wierszy: ";
  std::cin >> rowNumber;

  for (unsigned int row = 0; row < rowNumber; ++row) {
    for (unsigned int col = 0; col < rowNumber - row - 1; ++col) {
      std::cout.put('.');
    }
    for (unsigned int col = 0; col < row + 1; ++col) {
      std::cout.put('*');
    }
    std::cout << std::endl;
  }

  return 0;
}
