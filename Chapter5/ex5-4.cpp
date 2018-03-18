// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  4

#include <iostream>

const double simpleInterest = 0.10;
const double compoundInterest = 0.05;

const double initialBalance = 100.0;

int main(void) {

  double balanceDafne {initialBalance};
  double balanceCleo {initialBalance};

  unsigned int years = 0;
  do {
    balanceDafne += simpleInterest * initialBalance;
    balanceCleo += compoundInterest * balanceCleo;
    ++years;
  } while (balanceCleo < balanceDafne);

  std::cout << "Cleo osiągnie większy zysk po: " << years << " latach." << std::endl;
  std::cout << "Stan konta Dafne: " << balanceDafne << " $. " << std::endl;
  std::cout << "Stan konta Cleo:  " << balanceCleo << " $. " << std::endl;

  return 0;
}
