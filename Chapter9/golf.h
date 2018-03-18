#ifndef _GOLF_H_
#define _GOLF_H_

const int Len = 40;

struct Golf {
  char fullname[Len];
  int handicap;
};

// wersja nieinteraktywna
// funkcja ustawia w strukturze golf zadane nazwisko i handicap
// na podstawie argumentów wywowałania
bool setgolf(Golf& g, const char *name, int hc);

// wersja interaktywna
// funkcja pobiera nazwisko i wartość handicapu od użytkownika
// i ustawia pola struktury zgodnie z pobranymi wartościami.
// Zwraca 1, jeśli się udało się odczytać z wejścia wartość pola name,
// albo 0, kiedy pole name jest ciągiem pustym.
bool setgolf(Golf& g);

// ustawia handicap gracza
void handicap(Golf& g, int hc);

// wyświetla zawartość pól struktury Golf
void showgolf(const Golf& g);

#endif
