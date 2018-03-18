// Book:        C++ Primer Plus
// Chapter:     15
// Exercise:    2

#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  double x, y, z;

  cout << "Enter two numbers: ";
  while (cin >> x >> y) {
    try {
      z = hmean(x, y);
      cout << "Harmonic average numbers " << x << " and " << y
        << " equals: " << z << endl;
      z = gmean(x, y);
      cout << "Geometric average numbers " << x << " and " << y
        << " equals: " << z << endl;
      cout << "Enter next pair (q for end): ";
    }
    catch(const bad_gmean& e) {
      std::cout << e.what();
      break;
    }
    catch(const std::exception& e) {
      cout << e.what();
      cout << "Try again.\n";
      continue;
    }
  }
  cout << "*** END ***" << endl;

  return 0;
}

double hmean(double a, double b) {
  if (a == -b)
    throw bad_hmean(a, b);
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0)
    throw bad_gmean(a, b);
  return std::sqrt(a * b);
}
