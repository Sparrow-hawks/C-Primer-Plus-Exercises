// Book:      C++ Primer Plus
// Chapter:   13
// Exercise:  3

#include <iostream>
#include <string>
#include "dma.h"

const int MAX = 3;

int main() {

  std::string label, color, style;
  int rating, kind;

  DMA* arrayDMA[MAX];

  for (int i = 0; i < MAX; ++i) {
    std::cout << "Enter label: ";
    std::cin >> label;
    std::cout << "Enter rating: ";
    std::cin >> rating;
    std::cout << "Enter [1] for baseDMA, [2] for lacksDMA, [3] for hasDMA: ";
    std::cin >> kind;
    if (kind == 1) {
      arrayDMA[i] = new baseDMA(label.c_str(), rating);
    } else if (kind == 2) {
      std::cout << "Enter name of color: ";
      std::cin >> color;
      arrayDMA[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
    } else {
      std::cout << "Enter name of style: ";
      std::cin >> style;
      arrayDMA[i] = new hasDMA(style.c_str(), label.c_str(), rating);
    }

  }

  for (int i = 0; i < MAX; ++i) {
    arrayDMA[i]->View();
  }

  for (int i = 0; i < MAX; ++i) {
    std::cout << *arrayDMA[i] << std::endl;
  }

  return 0;
}
