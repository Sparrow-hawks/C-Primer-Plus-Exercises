// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  5

#include <iostream>

template<typename T>
T max5(const T *array) {
  T max = array[0];
  for (size_t i = 1; i < 5; ++i) {
    if (array[i] > max)
      max = array[i];
  }
  return max;
}

int main(void) {

  int inumbers[5] = {-18, 24, 2, 39, -40};
  double dnumbers[5] = {2.8, -3.4, 5.4, -1.1, 0.4};

  std::cout << "Integer maxiumum: " << max5(inumbers) << std::endl;
  std::cout << "Double maximum:   " << max5(dnumbers) << std::endl;

  return 0;
}
