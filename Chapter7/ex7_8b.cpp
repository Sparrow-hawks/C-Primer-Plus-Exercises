// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  8b

#include <iostream>

const int Seasons = 4;
const char *Snames[Seasons] =
{ "Wiosna", "Lato", "Jesień", "Zima" };

struct Array {
  double data[Seasons];
};

void fill(Array *ps, int len);
void show(Array ds, int len);

int main(void) {
  Array expenses;
  fill(&expenses, Seasons);
  show(expenses, Seasons);

  return 0;
}

void fill (Array *ps, int len) {
  using namespace std;

  for (int i = 0; i < len; ++i) {
    cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
    cin >> ps->data[i];
  }
}

void show(Array ds, int len) {
  using namespace std;

  double total = 0.0;
  cout << "\nWYDATKI\n";
  for (int i = 0; i < Seasons; ++i) {
    cout << Snames[i] << ": " << ds.data[i] << " zł" << endl;
    total += ds.data[i];
  }
  cout << "Łącznie wydatki roczne: " << total << " zł" << endl;
}
