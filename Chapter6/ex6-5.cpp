// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  5

#include <iostream>

const double taxes[4] = {0.0, 0.1, 0.15, 0.20};
const unsigned int tresholds[4] = {5000, 10000, 20000, 35000};

int main(void) {
  std::cout << "Wprowadź swój dochód: ";
  int income;
  while (std::cin >> income && income > 0) {
    double tax = 0.0;

    for (size_t i = 0; i < 4 && income > 0; ++i) {
      if (income > tresholds[i]) {
        tax += tresholds[i] * taxes[i];
        income -= tresholds[i];
      } else {
        tax += income * taxes[i];
        income = 0;
      }
    }

    std::cout << "Podatek do zapłaty: " << tax << std::endl;
    std::cout << "Wprowadź swój dochód: ";
  }

  return 0;
}
