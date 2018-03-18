// Book:      C++ Primer Plus
// Chapter:   2
// Exercise:  7

#include <iostream>

void display(int h, int m);

int main(void) {

  int hour, minutes;

  std::cout << "Podaj liczbę godzin: ";
  std::cin >> hour;
  std::cout << "Podaj liczbę minut: ";
  std::cin >> minutes;

  display(hour, minutes);

  return 0;
}

void display(int h, int m) {
  std::cout << "Czas: " << h << ":" << m << std::endl;
}
