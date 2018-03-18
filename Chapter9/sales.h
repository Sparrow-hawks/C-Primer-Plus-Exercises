#ifndef _SALES_H_
#define _SALES_H_

namespace SALES {
  const int QUARTERS = 4;

  struct Sales {
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  };

  // kopiuje najmniejszy z czterech lub n elementów z tablicy ar
  // do składowej sales struktury s i oblicza oraz zachowuje w odpowiednich
  // składowych struktury sales wartości: średnią, minimalną i maksymalną;
  // zeruje pozostałe elementy tablicy sales (jeśli są);
  void setSales(Sales& s, const double ar[], int n);

  // pobiera interaktywnie informacje dla 4 kwartałów,
  // zachowuje je w składowej sales struktury s i oblicza oraz zachowuje
  // w odpowiednich składowych s wartość średnią, minimalną i maksymalną;
  void setSales(Sales& s);

  // wyświetla komplet informacji ze struktury s
  void showSales(const Sales& s);
}

#endif
