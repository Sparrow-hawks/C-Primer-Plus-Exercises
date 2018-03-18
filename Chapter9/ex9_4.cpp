// Book:      C++ Primer Plus
// Chapter:   9
// Exercise:  4

#include <iostream>
#include "sales.h"

int main() {
  SALES::Sales s1, s2;

  SALES::setSales(s1);

  double ar[SALES::QUARTERS] = {1.7, 3.2, 2.6, 7.4};
  SALES::setSales(s2, ar, sizeof (ar) / sizeof (ar[0]));

  SALES::showSales(s1);
  SALES::showSales(s2);

  return 0;
}
