#include <iostream>
#include <algorithm>
#include <numeric>
#include "sales.h"

namespace SALES {

Sales::Sales(const double *sales, int n) {
  for (int i = 0; i < QUARTERS; ++i)
    m_Sales[i] = 0.0;
  for (int i = 0; i < n; ++i)
    m_Sales[i] = sales[i];

  m_Count = n;
}

Sales::Sales() {
  std::cout << "Enter data for 4 seasons: (q - ends:)" << std::endl;

  int seasons = 0;
  double ar[QUARTERS] = {0.0, 0.0, 0.0, 0.0};

  for (seasons = 0; seasons < QUARTERS; ) {
    std::cout << "Season [" << seasons + 1 << "]: ";
    std::cout.flush();
    if (!(std::cin >> ar[seasons]))
      break;
    else
      ++seasons;
  }

  *this = Sales(ar, seasons);
}

void Sales::show() const {
  std::cout << "Sales: ";
  for (size_t i = 0; i < m_Count; ++i)
    std::cout << m_Sales[i] << " ";

  std::cout << std::endl;
  std::cout << "Average: " << getAvg() << std::endl;
  std::cout << "Max: " << getMax() << std::endl;
  std::cout << "Min: " << getMin() << std::endl;
}

double Sales::getAvg() const {
  return std::accumulate(m_Sales, m_Sales + m_Count, 0) / static_cast<double>(m_Count);
}

double Sales::getMax() const {
  return *std::max_element(m_Sales, m_Sales + m_Count);
}

double Sales::getMin() const {
  return *std::min_element(m_Sales, m_Sales + m_Count);
}


}
