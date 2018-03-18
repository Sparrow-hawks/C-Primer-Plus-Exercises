// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  10

#include <iostream>
#include <cfloat>
#include <string>
#include <array>

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

typedef double (*pf)(double, double);

double calculate(double x, double y, pf action);

const size_t numberOfActions = 4;

int main(void) {
  std::array<std::string, numberOfActions> actionName {{"Dodawanie", "Odejmowanie", "Mnożenie", "Dzielenie"}};
  
  pf pfs[numberOfActions] = {add, sub, mul, div};
  
  std::cout << "Podaj dwie liczby: ";

  double x, y;
  while (std::cin >> x >> y) {
    for (size_t i = 0; i < numberOfActions; ++i) {
      std::cout << i << ". " << actionName[i] << ": " << calculate(x, y, pfs[i]) << std::endl;
    }
    std::cout << "Podaj dwie liczby (q - koniec): ";
    std::cout.flush();
  }
  std::cout << "Do widzenia!" << std::endl;
  
  return 0;
}

double add(double x, double y) {
  return x + y;
}

double sub(double x, double y) {
  return x - y;
}

double mul(double x, double y) {
  return x * y;
}

double div(double x, double y) {
  if (y != 0.0)
    return x / y;
  else {
    std::cerr << "Błąd: dzielenie przez 0! "; 
    return DBL_MAX;
  }
}

double calculate(double x, double y, pf action) {
  return (*action)(x, y);
}   
