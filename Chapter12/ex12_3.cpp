// Book:      C++ Primer Plus
// Chapter:   12
// Exercise:  3

#include <iostream>
#include "stock_2.h"

const int STKS = 4;
int main() {
  Stock stocks[STKS] = {
    Stock("NanoSmart", 12, 20.0),
    Stock("BurakPOL", 200, 2.0),
    Stock("GruzPOL", 130, 3.25),
    Stock("FutroPol", 60, 6.65),
  };

  std::cout << "Investment portfolio:\n";
  int st;
  for (st = 0; st < STKS; st++)
    std::cout << stocks[st] << std::endl;
  const Stock *top = &stocks[0];
  for (st = 0; st < STKS; st++)
    top = &top->topval(stocks[st]);

  std::cout << "\nMost valueable packet:\n";
  std::cout << *top << std::endl;

  return 0;
}
