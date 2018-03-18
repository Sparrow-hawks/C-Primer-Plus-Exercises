// Book:      C++ Primer Plus
// Chapter:   18
// Exercise:  3

#include <iostream>

template<typename T>
long double sum_values(const T& element) {
  return element;
}

template<typename T, typename... Args>
long double sum_values(const T& element, const Args&... args) {
  return element + sum_values(args...);
}

int main() {

  std::cout << sum_values(1, 3.5, -2.8, 15) << std::endl;

  return 0;
}
