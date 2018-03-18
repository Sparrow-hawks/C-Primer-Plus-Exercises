// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  2

#include <iostream>
#include "person.h"

int main() {

  Person one;
  Person two("Stephan");
  Person three("Albert", "Einstein");

  one.show(); std::cout << std::endl;
  one.formalShow(); std::cout << std::endl;

  two.show(); std::cout << std::endl;
  two.formalShow(); std::cout << std::endl;

  three.show(); std::cout << std::endl;
  three.formalShow(); std::cout << std::endl;

  return 0;
}
