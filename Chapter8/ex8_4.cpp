// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  4

#include <iostream>
#include <cstring>

struct String {
  char *str;      // wskazuje łańcuch
  int ct;         // długość łańcucha (bez '\0')
};

void set(String& str, const char *cstr);
void show(const char *cstr, unsigned int cnt = 1);
void show(const String& str, unsigned int cnt = 1);

int main(void) {
  String beany;
  char testing[] = "Rzeczywistość to już nie to, co kiedyś.";

  set(beany, testing); // pierwszy parametr jako referencja,
  // alokacja pamięci na wynik sprawdzania,
  // ustawienie pola str struktury beany tak, by wskazywała nowy blok,
  // kopiowanie testing do nowego bloku,
  // ustawienie pola ct zmiennej beany

  show(beany);
  show(beany, 2);

  testing[0] = 'D';
  testing[1] = 'u';

  show(testing);
  show(testing, 3);
  show("Gotowe!");

  return 0;
}

void set(String& str, const char *cstr) {
  str.str = new char[strlen(cstr) + 1];

  strncpy(str.str, cstr, strlen(cstr) + 1);

  str.ct = strlen(cstr);
}

void show(const char *cstr, unsigned int cnt) {
  for (unsigned int i = 0; i < cnt; ++i)
    std::cout << cstr;
  std::cout << std::endl;
}

void show(const String& str, unsigned int cnt) {
  for (unsigned int i = 0; i < cnt; ++i)
    std::cout << str.str;
  std::cout << std::endl;
}
