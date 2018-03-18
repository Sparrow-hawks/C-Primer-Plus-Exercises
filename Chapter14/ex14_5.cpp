// Book:      C++ Primer Plus
// Chapter:   14
// Exercise:  5

#include <iostream>
#include "emp.h"

using namespace std;

int main() {
  employee em("Sheldon", "Cooper", "");
  cout << em << endl;
  em.ShowAll();

  manager ma("Rajesh", "Koothrappali", "Astrophysicist", 5);
  cout << ma << endl;
  ma.ShowAll();

  fink fi("Howard", "Wolowitz", "Astronaut", " 	Bernadette Rostenkowski");
  cout << fi << endl;
  fi.ShowAll();

  highfink hf(ma, "Leonard Hofstadter");
  hf.ShowAll();

  cout << "Press any key to go further: \n";
  cin.get();

  highfink hf2;
  hf2.SetAll();

  cout << "Use abstr_emp* pointer :\n";
  abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
  for (int i = 0; i < 4; ++i)
    tri[i]->ShowAll();

  return 0;
}
