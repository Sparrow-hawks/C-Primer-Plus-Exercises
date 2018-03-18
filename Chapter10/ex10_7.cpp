// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  7

#include <iostream>
#include "plorg.h"

int main() {
  Plorg p1;
  Plorg p2 ("Plorgb");

  p1.show(); std::cout << std::endl;
  p2.show(); std::cout << std::endl;

  p1.setSatiety(100);
  p2.setSatiety(20);

  p1.show(); std::cout << std::endl;
  p2.show(); std::cout << std::endl;

  return 0;
}
