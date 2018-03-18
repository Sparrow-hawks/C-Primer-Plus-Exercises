// Book:      C++ Primer Plus
// Chapter:   13
// Exercise:  1

#include <iostream>
#include "classic.h"

void Bravo(const CD& cd);

int main() {
  CD c1((char*)"Beatles", (char*)"Capitol", 14, 35.5);
  Classic c2 = Classic((char*)"Sonata fortepianowa B-dur, Fantazja C-moll", (char*)"Alfred Brendel",
    (char*)"Philips", 2, 57.17);

  CD *pcd = &c1;

  std::cout << "Direct object use:\n";
  c1.Report();
  c2.Report();

  std::cout << "Use CD pointer type:\n";
  pcd->Report();
  pcd = &c2;
  pcd->Report();

  std::cout << "Function call with base reference type:\n";
  Bravo(c1);
  Bravo(c2);

  std::cout << "Assigments tests:\n";
  Classic copy;
  copy = c2;
  copy.Report();

  return 0;
}

void Bravo(const CD& disc) {
  disc.Report();
}
