// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  4

#include <iostream>

long double probality(unsigned numbers, unsigned picks);

int main(void) {

  double total, choices, mega;
  std::cout << "Podaj największą liczbę, jaką można wybrać, oraz\n"
    "liczbę skreśleń, oraz megaliczbę:\n";
  while ((std::cin >> total >> choices >> mega) && choices <= total) {
    std::cout << "Szansa wygranej to jeden do ";
    std::cout << probality(total, choices) * probality(mega, 1);
    std::cout << ".\n";
    std::cout << "Następne dwie liczby (q, aby zakończyć): ";
    std::cout.flush();
  }

  std::cout << "Do widzenia!" << std::endl;

  return 0;
}

long double probality(unsigned numbers, unsigned picks) {
  long double result = 1.0;
  long double n = numbers;

  for (unsigned p = picks; p > 0; n--, p--)
    result = result * n / p;

  return result;
}
