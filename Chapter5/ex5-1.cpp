// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  1

#include <iostream>

int main(void) {

  unsigned int low, high, result = 0;

  std::cout << "Podaj dwie liczby dodatnie: ";
  std::cin >> low >> high;

  for (unsigned int i = low; i <= high; ++i) {
    result += i;
  }

  std::cout << "Suma liczb całkowitych z przedziału ["
    << low << " : " << high << "] wynosi: " << result << "." << std::endl;

  return 0;
}
