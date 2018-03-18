// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  1

#include <iostream>

double avgHarmonic(double x, double y);

int main(void) {

  std::cout << "Podaj dwie liczby [0 - koniec]: ";

  double x, y;
  while (std::cin >> x >> y && (x != 0 && y != 0)) {
    std::cout << "Średnia harmoniczna " << x << " i " << y << " wynosi: ";
    std::cout << avgHarmonic(x, y) << std::endl;
    std::cout << "Podaj dwie liczby [0 - koniec]: ";
    std::cout.flush();
  }
  std::cout << "Do widzenia!" << std::endl;

  return 0;
}

double avgHarmonic(double x, double y) {
  return 2.0 * x * y / (x + y);
}
