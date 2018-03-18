// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  3

#include <iostream>

int main(void) {

std::cout << "Podaj liczby [0 - koniec]: ";
unsigned int number, sum = 0;
do {
  std::cin >> number;

  sum += number;
  std::cout << "Suma dotychczasowo wprowadzonych liczby wynosi: "
    << sum << "." << std::endl;

} while (number);

std::cout << "Koniec zabawy!" << std::endl;

  return 0;
}
