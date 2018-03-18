#include <iostream>
#include <algorithm>
#include <numeric>
#include "sales.h"

namespace SALES {

void setSales(Sales& s, const double ar[], int n) {
  for (int i = 0; i < QUARTERS; ++i)
    s.sales[i] = 0.0;

  for (int i = 0; i < n; ++i)
    s.sales[i] = ar[i];

  s.average = std::accumulate(ar, ar + n, 0);
  s.average /= n;

  s.max = *std::max_element(ar, ar + n);
  s.min = *std::min_element(ar, ar + n);
}

void setSales(Sales& s) {
  std::cout << "Enter data for 4 seasons: (q - ends):" << std::endl;

  int seasons = 0;
  double ar[QUARTERS] {0.0, 0.0, 0.0, 0.0};
  for (seasons = 0; seasons < QUARTERS; ) {
    std::cout << "Season [" << seasons + 1 << "]: ";
    std::cout.flush();
    if (!(std::cin >> ar[seasons++]))
      break;
  }
  setSales(s, ar, seasons);
}

void showSales(const Sales& s) {
  std::cout << "Sales: ";
  for (size_t i = 0; i < QUARTERS; ++i)
    std::cout << s.sales[i] << " ";
  std::cout << std::endl;
  std::cout << "Average: " << s.average << std::endl;
  std::cout << "Max: " << s.max << std::endl;
  std::cout << "Min: " << s.min << std::endl;
}

}
