// Book:      C++ Primer Plus
// Chapter:   2
// Exercise:  5

#include <iostream>

int celsToFahr(int temp);

int main(void) {

  int celsTemp;
  std::cout << "Podaj temperaturę w stopniach Celsjusza: ";
  std::cin >> celsTemp;
  std::cout << celsTemp << " stopnie Celsjusza to " <<
    celsToFahr(celsTemp) << " stopnie Fahrenheita." << std::endl;

  return 0;
}

int celsToFahr(int temp) {
  return 1.8 * temp + 32;
}
