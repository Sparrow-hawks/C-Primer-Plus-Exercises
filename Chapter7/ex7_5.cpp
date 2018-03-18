// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  5

#include <iostream>

unsigned long long factorial (unsigned long long number);

int main(void) {

  unsigned int number;

  std::cout << "Witaj w programie liczącym silnie w sposób rekurencyjny: " << std::endl;
  std::cout << "Podaj liczbę: ";
  while (std::cin >> number) {
    std::cout << "Silnia " << number << "! wynosi: " << factorial(number) << std::endl;
    std::cout << "Podaj następną liczbę (q, aby zakończyć): ";
    std::cout.flush();
  }
  std::cout << "Do widzenia!" << std::endl;

  return 0;
}

unsigned long long factorial (unsigned long long number) {
  if (number < 2)
    return 1;
  else
    return number * factorial (number - 1);
}
