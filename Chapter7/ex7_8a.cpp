// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  8a

#include <iostream>

const int Seasons = 4;
const char *Snames[Seasons] =
{ "Wiosna", "Lato", "Jesień", "Zima" };

void fill(double *pa, int len);
void show(const double *da, int len);

int main(void) {
  double expenses[Seasons];
  fill(expenses, Seasons);
  show(expenses, Seasons);

  return 0;
}

void fill (double *pa, int len) {
  using namespace std;

  for (int i = 0; i < len; ++i) {
    cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
    cin >> *(pa + i);
  }
}

void show(const double *da, int len) {
  using namespace std;

  double total = 0.0;
  cout << "\nWYDATKI\n";
  for (int i = 0; i < Seasons; ++i) {
    cout << Snames[i] << ": " << da[i] << " zł" << endl;
    total += da[i];
  }
  cout << "Łącznie wydatki roczne: " << total << " zł" << endl;
}
