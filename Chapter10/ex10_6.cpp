// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  6

#include <iostream>
#include "move.h"

int main() {
  Move m1 (10, 20);
  Move m2 (30, 40);

  m1.show();  std::cout << std::endl;
  m2.show();  std::cout << std::endl;

  Move m3 = m1.add(m2);

  m3.show();  std::cout << std::endl;

  m1.reset(1, 2);
  m2.reset(3, 4);
  m3.reset(0, 0);

  m1.show();  std::cout << std::endl;
  m2.show();  std::cout << std::endl;
  m3.show();  std::cout << std::endl;

  return 0;

}
