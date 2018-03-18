// Book:      C++ Primer Plus
// Chapter:   11
// Exercise:  2

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "vect.h"

int main() {

  using namespace std;
  using VECTOR::Vector;

  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  unsigned long min = ULONG_MAX;
  unsigned long max = 0;
  unsigned long avg = 0;
  unsigned int N;
  double target;
  double dstep;
  cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
  while (cin >> target) {
    cout << "Podaj długość kroku: ";
    if (!(cin >> dstep))
      break;
    cout << "Podaj liczbę prób: ";
    if (!(cin >> N))
      break;

    for (unsigned int i = 0; i < N; ++i) {

      steps = 0;
      result.reset(0.0, 0.0);
      while (result.magval() < target) {
        direction = rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        result = result + step;
        steps++;
      }
      avg += steps;
      if (steps > max)
        max = steps;
      if (steps < min)
        min = steps;
    }

    cout << "Po " << steps << " krokach delikwent "
      "osiągnął położenie:\n";
    cout << result << endl;
    result.polar_mode();
    cout << " czyli\n" << result << endl;
    steps = 0;
    result.reset(0.0, 0.0);

    cout << "Srednio po: " << avg / N << " krokach." << endl;
    cout << "Minimalnie po: " << min << " krokach." << endl;
    cout << "Maksymalnie po: " << max << " krokach." << endl;

    avg = 0;
    max = 0;
    min = ULONG_MAX;

    cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
  }
  cout << "Koniec!\n";

  return 0;
}
