// Book:      C++ Primer Plus
// Chapter:   13
// Exercise:  4

#include <iostream>
#include "port.h"

int main() {

  Port p1("Carlo Rossi", "Red", 10);
  VintagePort p2("Martini", 4, "Velvet", 2004);

  std::cout << "Direct object use:\n";
  p1.Show();
  p2.Show();

  std::cout << "Direct object use:\n";
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;

  std::cout << "Use Port pointer:\n";
  Port *pPort = &p1;
  pPort->Show();
  pPort = &p2;
  pPort->Show();

  std::cout << "Use Port pointer:\n";
  pPort = &p1;
  std::cout << *pPort << std::endl;
  pPort = &p2;
  std::cout << *pPort << std::endl;

  std::cout << "Assigments tests:\n";
  VintagePort p3;
  p3 = p2;
  p2.Show();

  return 0;
}
