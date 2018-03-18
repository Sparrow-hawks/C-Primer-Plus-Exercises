// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    5

#include <iostream>
#include <string>

int main(void) {

  const size_t Size {80};

  struct CandyBar {
    char brand[Size];
    double weight;
    unsigned int calories;
  } snack = {
    "Mocha Munch",
    2.3,
    350
  };

  std::cout << "Producent: " << snack.brand << std::endl;
  std::cout << "Waga: " << snack.weight << std::endl;
  std::cout << "Kalorie: " << snack.calories << std::endl;

  return 0;
}
