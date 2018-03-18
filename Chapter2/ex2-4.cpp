// Book:      C++ Primer Plus
// Author:    Sparrowhawk 
// Chapter:   2
// Exercise:  4

#include <iostream>

int main(void) {
  int age;

  std::cout << "Podaj swój wiek: ";
  std::cin >> age;
  std::cout << "Twój wiek w miesiącach wynosi " << age * 12 << "." << std::endl;

  return 0;
}
