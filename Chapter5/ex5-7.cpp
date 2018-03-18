// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  7

#include <iostream>
#include <string>

int main(void) {

  struct Car {
    std::string brand;
    unsigned int mYear;
  };

  unsigned int numberOfCars = 0;

  std::cout << "Ile samochodów chcesz skatalogować? ";
  std::cin >> numberOfCars;
  std::cin.get();

  Car *cars = new Car[numberOfCars];

  for (unsigned int i = 0; i < numberOfCars; ++i) {
    std::cout << "Proszę podać markę: ";
    std::cout.flush();
    std::getline(std::cin, cars[i].brand);
    std::cout << "Rok produkcji: ";
    std::cout.flush();
    std::cin >> cars[i].mYear;
    std::cin.get();
  }

  for (unsigned int i = 0; i < numberOfCars; ++i) {
    std::cout << cars[i].mYear << " " << cars[i].brand << std::endl;
  }

  delete[] cars;

  return 0;
}
