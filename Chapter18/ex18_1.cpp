// Book:      C++ Primer Plus
// Chapter:   18
// Exercise:  1

#include <iostream>
#include <initializer_list>
#include <numeric>

template<typename T>
double average_list(std::initializer_list<T> list);

int main() {
  using namespace std;

  auto q = average_list({15.4, 10.7, 9.0});
  cout << q << endl;

  cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

  auto ad = average_list<double>({'A', 70, 65.33});

  cout << ad << endl;

  return 0;
}

template<typename T>
double average_list(std::initializer_list<T> list) {
  return std::accumulate(list.begin(), list.end(), 0) / static_cast<double> (list.size());
}
