// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  6

#include <iostream>

size_t fill_array(double *numbers, size_t len);
void show_array(const double *numbers, size_t len);
void reverse_array(double *numbers, size_t len);

const size_t maxLength = 10;

int main(void) {

  double numbers[maxLength];

  size_t size = fill_array(numbers, maxLength);

  show_array(numbers, size);

  reverse_array(numbers, size);

  show_array(numbers, size);

  return 0;
}

size_t fill_array(double *numbers, size_t len) {
  size_t size = 0;
  std::cout << "Podaj " << len << " liczb (q - koniec):" << std::endl;
  for (size = 0; size < len; ++size) {
    std::cout << "Wartość [" << size + 1 << "]: ";
    if (!(std::cin >> numbers[size]))
      break;
  }
  return size;
}

void show_array(const double *numbers, size_t len) {
  std::cout << "Zawartość tablicy:" << std::endl;
  for (size_t i = 0; i < len; ++i)
    std::cout << *(numbers + i) << " ";
  std::cout << std::endl;
}

void reverse_array(double *numbers, size_t len) {
  double t;
  for (size_t i = 0; 2 * i < len; ++i) {
    t = numbers[i];
    numbers[i] = numbers[len - 1 - i];
    numbers[len - 1 - i] = t;
  }
}
