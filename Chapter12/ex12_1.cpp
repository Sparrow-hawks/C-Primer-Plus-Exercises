// Book:      C++ Primer Plus
// Chapter:   12
// Exercise:  1

#include <iostream>
#include "cow.h"

void checkCow(Cow cow);

int main() {
  {
    Cow cow1("Homer", "Reading", 165);
    Cow cow2("Angus", "Eating", 180);
    Cow cow3;

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    cow3 = cow1;
    cow3.ShowCow();

    checkCow(cow2);
  }
  return 0;
}

void checkCow(Cow cow) {
  std::cout << "Check cow: " << std::endl;
  cow.ShowCow();
  std::cout << "Cow checked." << std::endl;
}
