// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  1

#include <iostream>

int main(int argc, char* argv[]) {

	const int ftToInch {12};
  int height;

  std::cout << "Podaj swój wzrost w calach: ";
  std::cin >> height;

  std::cout << "Twój wzrost: " << height / ftToInch << " stóp, " 
		<< height % ftToInch << " cali." << std::endl;

  return 0;
}
