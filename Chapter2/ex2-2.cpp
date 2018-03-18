// Book:      C++ Primer Plus
// Chapter:   2
// Exercise:  2

#include <iostream>

int main(void) {

  int miles;
  std::cout << "Wprowadź odległość w milach morskich: ";
  std::cin >> miles;
  std::cout << "Odległość w metrach wynosi: " << miles * 1852 << "." << std::endl;

  return 0;
}
