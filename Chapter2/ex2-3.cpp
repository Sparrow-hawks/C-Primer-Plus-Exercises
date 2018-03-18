//Book:     C++ Primer Plus
//Chapter:  2
//Exercise: 3

#include <iostream>

void foo1(void);
void foo2(void);

int main(void) {

  foo1();
  foo1();
  foo2();
  foo2();

  return 0;
}

void foo1(void) {
  std::cout << "Entliczek pentliczek" << std::endl;
}

void foo2(void) {
  std::cout << "Czerwony stoliczek" << std::endl;
}
