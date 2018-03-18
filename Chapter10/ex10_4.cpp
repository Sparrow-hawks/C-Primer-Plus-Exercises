// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  4

#include <iostream>
#include "sales.h"

int main() {

  double ar[4] = {1.7, 3.2, 2.6, 7.4};

  SALES::Sales s1, s2 (ar, sizeof(ar) / sizeof (ar[0]));

  s1.show();
  s2.show();

  return 0;
}
