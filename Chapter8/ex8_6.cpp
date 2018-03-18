// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  6

#include <iostream>
#include <cstring>

template<typename T>
T maxn(const T *array, size_t len) {
  T max = array[0];
  for (size_t i = 1; i < len; ++i) {
    if (array[i] > max)
      max = array[i];
  }
  return max;
}

template<>
const char* maxn<const char*>(const char * const str[], size_t len) {
  size_t max = strlen(str[0]);
  const char* adr = str[0];
  for (size_t i = 0; i < len; ++i) {
    if (strlen(str[i]) > max) {
      max = strlen(str[i]);
      adr = str[i];
    }
  }
  return adr;
}

int main(void) {

  int inumbers[5] = {-18, 24, 2, 39, -40};
  double dnumbers[4] = {2.8, -3.4, 5.4, -1.1};

  const char* names[] = {
    "Leoanard Hofstader",
    "Sheldon Lee Cooper",
    "Penny",
    "Howard Wolowitz",
    "Rajesh Koothrappali",
    "Bernadette Rostenkowksi-Wolowitz",
    "Amy Farrah Fowler",
  };

  std::cout << "Max from integers: " << maxn(inumbers, 5) << std::endl;
  std::cout << "Max from doubles:  " << maxn(dnumbers, 4) << std::endl;
  std::cout << "Max from cstring:  " << maxn(names, 7) << std::endl;

  return 0;
}
