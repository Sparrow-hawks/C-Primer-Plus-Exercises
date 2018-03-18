// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  7

#include <iostream>

int main(void) {

  const float usgToLiter {3.875F}; 
  const float ueDistance {62.14F};

  float ueFuelBurnRatio, usFuelBurnRatio;
  std::cout << "Podaj średnie zużycie paliwa w [l/100km]: ";
  std::cin >> ueFuelBurnRatio;

  usFuelBurnRatio = ueDistance / (ueFuelBurnRatio / usgToLiter);

  std::cout << "Średnie zużycie paliwa w systemie amerykańskim wynosi: " << usFuelBurnRatio << " [mpg]." << std::endl; 

  return 0;
}
