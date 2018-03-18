// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  1

#include <iostream>
#include "bankaccount.h"

int main() {

  BankAccount acc_1 ("Sheldon Cooper", "90 1285 3331 3994 2915 7869 9878", 0.0);
  BankAccount acc_2 ("Leonard Hofstader", "90 1286 3525 3158 3558 1587 1586", 1000.0);

  acc_1.show();
  acc_2.show();

  acc_1.payIn(12000);
  acc_2.payOut(1400);

  acc_1.show();
  acc_2.show();

  return 0;
}
