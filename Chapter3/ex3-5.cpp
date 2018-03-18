// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  5

#include <iostream>

int main(void) {

  long long int worldPopulation, polandPopulation;

  std::cout << "Podaj liczbę ludności świata: ";
  std::cin >> worldPopulation;
  std::cout << "Podaj liczbę ludności Polski: ";
  std::cin >> polandPopulation;

  double populationRatio = polandPopulation / static_cast<double>(worldPopulation) * 100.0;

  std::cout << "Populacja Polski stanowi " << populationRatio << "% populacji świata." << std::endl;

  return 0;
}
