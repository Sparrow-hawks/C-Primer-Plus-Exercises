// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    9

#include <iostream>
#include <string>

int main(void) {

  struct CandyBar {
    std::string brand;
    double weight;
    unsigned int calories;
  };

  CandyBar *candyBars = new CandyBar[3];

  candyBars[0] = {"Smatties", 2.5, 400};
  candyBars[1] = {"Snickers", 2.7, 450};
  candyBars[2] = {"Milkyway", 2.1, 390};

  std::cout << "Producent" << "\t" << "Waga" << "\t" << "Kalorie" <<std::endl;
  std::cout << candyBars[0].brand << "\t"
    << candyBars[0].weight << "\t"
    << candyBars[0].calories << std::endl;

  std::cout << candyBars[1].brand << "\t"
    << candyBars[1].weight << "\t"
    << candyBars[1].calories << std::endl;

  std::cout << candyBars[2].brand << "\t"
    << candyBars[2].weight << "\t"
    << candyBars[2].calories << std::endl;

  delete[] candyBars;

  return 0;
}
