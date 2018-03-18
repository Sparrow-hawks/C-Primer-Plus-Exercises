// Book:      C++ Primer Plus
// Chapter:   14
// Exercise:  1

#include <iostream>
#include "winec.h"

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  cout << "Podaj nazwę wina: ";
  char lab[50];
  cin.getline(lab, 50);
  cout << "Podaj liczbę roczników: ";
  int yrs;
  cin >> yrs;

  Wine holding(lab, yrs); // Zapisuje nazwę, liczbę roczników i przekazuje informację o
                          // tej liczbie do tablicy
  holding.GetBottles();   // Pobiera dane o roczniku i liczbie butelek
  holding.Show();         // Wyświetla zawartość obiektu

  const int YRS = 3;
  int y[YRS] = {1993, 1995, 1998};
  int b[YRS] = {48, 60, 72};

  Wine more("Gushing Grape Red", YRS, y, b);  // Tworzy nowy obiekt, inicjalizuje za pomocą danych
                                              // w tablicach y oraz b
  more.Show();
  cout << "Łączna liczba butelek wina " << more.label() // Używa metody Label
    << ": " << more.sum() << endl;
  cout << "Koniec" << endl;

  return 0;
}
