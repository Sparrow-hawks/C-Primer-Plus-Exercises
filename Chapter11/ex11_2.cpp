// Book:      C++ Primer Plus
// Chapter:   11
// Exercise:  2

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect_2.h"

int main() {

  using namespace std;
  using VECTOR::Vector;

  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
  while (cin >> target) {
    cout << "Podaj długość kroku: ";
    if (!(cin >> dstep))
      break;

    std::ofstream outFile;
    outFile.open("Results.txt", std::ofstream::out | std::ofstream::trunc);

    if (!outFile.is_open()) {
      cout << "Nie mogę utworzyć pliku z raporterm!\n";

      exit(EXIT_FAILURE);
    }
    outFile << "Dystans do przejścia: " << target << ", długość kroku: " << dstep << endl;

    while (result.magval() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;

      step.rect_mode();

      outFile << steps << ": " << step << std::endl;

      steps++;

    }

    cout << "Po " << steps << " krokach delikwent "
      "osiągnął położenie:\n";
    cout << result << endl;
    result.polar_mode();
    cout << " czyli\n" << result << endl;

    result.rect_mode();
    outFile << "Po " << steps << " krokach delikwent "
      "osiągnął położenie:\n";
    outFile << result << endl;
    result.polar_mode();
    outFile << " czyli\n" << result << endl;
    steps = 0;
    result.reset(0.0, 0.0);

    outFile.close();

    cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
  }
  cout << "Koniec!\n";

  return 0;
}
