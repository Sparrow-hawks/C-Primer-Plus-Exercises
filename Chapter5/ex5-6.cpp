// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  6

#include <iostream>
#include <string>

int main(void) {
  const unsigned int monthInYear {12};
  const unsigned int numberOfYears {3};

  const std::string months[monthInYear] {
    "Styczeń", "Luty", "Marzec", "Kwiecień",
    "Maj", "Czerwiec", "Lipiec", "Sierpień",
    "Wrzesień", "Październik", "Listopad", "Grudzień"
  };

  int sellData[numberOfYears][monthInYear] {};

  for (unsigned int year = 0; year < numberOfYears; ++year) {
    std::cout << "Podaj miesięczną liczbę sprzedaży w " << year + 1 << " roku: " << std::endl;
    for (unsigned int month = 0; month < monthInYear; ++month) {
      std::cout << months[month] + ": ";
      std::cin >> sellData[year][month];
    }
  }

  unsigned int sellByYear = 0, sellAllYears = 0;

  std::cout << "Roczna suma sprzedaży wynosi: " << std::endl;
  for (unsigned int i = 0; i < numberOfYears; ++i) {
    sellByYear = 0;
    for (unsigned int m = 0; m < monthInYear; ++m) {
      sellByYear += sellData[i][m];
    }
    std::cout << "Rok " << i + 1 << ". :" << sellByYear << " szt." << std::endl;
    sellAllYears += sellByYear;
  }

  std::cout << "Łączna suma sprzedaży wynosi: " << sellAllYears << " szt." << std::endl;
  return 0;
}
