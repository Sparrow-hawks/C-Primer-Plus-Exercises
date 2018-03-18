// Book:      C++ Primer Plus
// Chapter:   2
// Exercise:  6

#include <iostream>

double lightYearsToAstroUnits(double lYears);

int main(void) {

  double lightYears, astroUnit;
  std::cout << "Podaj liczbę lat świetlnych: ";
  std::cin >> lightYears;

  astroUnit = lightYearsToAstroUnits(lightYears);

  std::cout << lightYears
    << " lat świetlnych = "
    << astroUnit
    << " jednostek astronomicznych."
    << std::endl;

  return 0;
}

double lightYearsToAstroUnits(double lYears) {
  return lYears * 63240.0;
}
