// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  7

#include <iostream>

const int Max = 5;

//prototypy funkcji
double *fill_array(double *begin, const double *end);
void show_array(const double *begin, const double *end);
void revalue(double r, double *begin, const double *end);

int main(void) {
  using namespace std;
  double properties[Max];

  double *end = fill_array(properties, properties + Max);
  show_array(properties, end);
  if (end - properties > 0) {
    cout << "Podaj czynnik zmiany wartości: ";
    double factor;
    while (!(cin >> factor)) {//nieliczbowa wartość na wejściu
      cin.clear();
      while (cin.get() != '\n')
        continue;
      cout << "Niepoprawna wartość; podaj liczbę: ";
    }
    revalue(factor, properties, end);
    show_array(properties, end);
  }
  cout << "Gotowe.\n";

  return 0;
}

double *fill_array(double *begin, const double *end) {
  using namespace std;
  double temp;
  int i = 0;
  double *pt = nullptr;
  for (pt = begin; pt != end; ++pt, ++i) {
    cout << "Podaj wartość nr " << i + 1 << ": ";
    cin >> temp;
    if (!cin) { //błędne dane
      cin.clear();
      while (cin.get() != '\n')
        continue;
      cout << "Błędne dane, wprowadzanie danych przerwane.\n";
      break;
    } else if (temp < 0) // nakaz zakończenia
      break;
    *pt = temp;
  }
  return pt;
}

// poniższa funkcja może użyć tablicy, której adres przekazano
// w ar, ale nie może jej modyfikować
void show_array(const double *begin, const double *end) {
  using namespace std;

  int i = 0;
  for (const double *pt = begin; pt != end; ++pt, ++i) {
    cout << "Nieruchomość nr " << i + 1 << ": ";
    cout << *pt << endl;
  }
}

// mnoży każdy element ar[] przez r
void revalue(double r, double *begin, const double *end) {
  for (double *pt = begin; pt != end; ++pt)
    *pt *= r;
}
