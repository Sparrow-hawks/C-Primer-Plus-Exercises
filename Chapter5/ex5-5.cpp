// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  5

#include <iostream>
#include <string>

int main(void) {
  const unsigned int monthInYear {12};
  const std::string months[monthInYear] {
    "Styczeń", "Luty", "Marzec", "Kwiecień",
    "Maj", "Czerwiec", "Lipiec", "Sierpień",
    "Wrzesień", "Październik", "Listopad", "Grudzień"
  };

  int sellByMonth[monthInYear] {};

  std::cout << "Podaj miesięczną liczbę sprzedaży: " << std::endl;
  for (unsigned int month = 0; month < monthInYear; ++month) {
    std::cout << months[month] + ": ";
    std::cin >> sellByMonth[month];
  }

  unsigned int sellByYear = 0;
  for (unsigned int i = 0; i < monthInYear; ++i) {
    sellByYear += sellByMonth[i];
  }

  std::cout << "Roczna suma sprzedaży wynosi: " << sellByYear << " szt." << std::endl;

  return 0;
}
