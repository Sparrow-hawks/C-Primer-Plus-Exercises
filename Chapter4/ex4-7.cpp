// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    7

#include <iostream>
#include <string>

int main(void) {

  struct Pizza {
    std::string brand;
    size_t diameter;
    double weight;
  } pizza;

  std::cout << "William Wingate jest analitykiem pizzy. Podaj mu niezbędne dane."
    << std::endl;

  std::cout << "Podaj producenta pizzy: ";
  std::getline(std::cin, pizza.brand);
  std::cout << "Podaj średnicę pizzy: ";
  std::cin >> pizza.diameter;
  std::cout << "Podaj wagę pizzy: ";
  std::cin >> pizza.weight;

  std::cout << "Podsumujmy wprowadzone dane: " << std::endl;
  std::cout << "Producent: " << pizza.brand << std::endl;
  std::cout << "Średnica:  " << pizza.diameter << std::endl;
  std::cout << "Waga:      " << pizza.weight << std::endl;

  return 0;
}
