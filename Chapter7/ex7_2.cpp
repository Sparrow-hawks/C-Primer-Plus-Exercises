// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  2

#include <iostream>

const size_t maxSize = 10;

size_t collectResults(unsigned int *results, size_t len);
void showResults(const unsigned int *results, size_t len);
double average(const unsigned int *begin, const unsigned int *end);

int main(void) {

  unsigned int golfMatchResults[maxSize];

  size_t size = collectResults(golfMatchResults, maxSize);

  showResults(golfMatchResults, size);

  std::cout << "Średnia wprowadzonych wyników wynosi: "
    << average(golfMatchResults, golfMatchResults + size) << std::endl;

  return 0;
}

size_t collectResults(unsigned int *results, size_t len) {
  std::cout << "Wprowadź wyniki gry w golfa [-1 - koniec]:" << std::endl;

  size_t size;
  int temp;
  for (size = 0; size < len; ++size) {
    std::cout << "Wynik [" << size + 1 << "]: ";
    std::cout.flush();
    std::cin >> temp;
    if (!std::cin.good()) {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cerr << "Błędne dane, przerywam!" << std::endl;
      break;
    }
    if (temp < 0)
      break;
    results[size] = temp;
  }

  return size;
}

void showResults(const unsigned int *results, size_t len) {
  std::cout << "Wyniki gry w golfa: ";
  for (size_t i = 0; i < len; ++i)
    std::cout << *(results + i) << " ";
  std::cout << std::endl;
}

double average(const unsigned int *begin, const unsigned int *end) {
  double result = 0.0;
  for (const unsigned int *pt = begin; pt != end; ++pt)
    result += *pt;

  return result / (end - begin);
}
