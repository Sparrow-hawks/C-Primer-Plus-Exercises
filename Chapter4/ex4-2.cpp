// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    2

#include <iostream>
#include <string>

int main(void) {
  using namespace std;

  string name;
  string dessert;

  cout << "Podaj swoje imię:\n";
  getline(cin, name);
  cout << "Podaj swój ulubiony deser:\n";
  getline(cin, dessert);

  cout << "Mam dla ciebie " << dessert;
  cout << ", " << name << ".\n";

  return 0;
}
