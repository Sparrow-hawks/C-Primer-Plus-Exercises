// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  2

#include <iostream>

int main(void) {

  const int ftToInches {12};
  const double inchToMeters {0.0254};
  const double poundToKg {2.2};

  int heightFt, heightInch, weigthlb;
  double heightInMeters, weightInKg;

  std::cout << "Podaj swój wzrost w stopach i calach, oraz wagę w funtach:" << std::endl;
  std::cout << "Najpierw podaj wzrost w stopach: ";
  std::cin >> heightFt;
  std::cout << "Następnie podaj cale: ";
  std::cin >> heightInch;
  std::cout << "Teraz waga w funtach: ";
  std::cin >> weigthlb;

  heightInMeters = (heightInch + heightFt * ftToInches) * inchToMeters;
  weightInKg = weigthlb / poundToKg;

  double BMI = weightInKg / (heightInMeters * heightInMeters);

  std::cout << "Twoje BMI wynosi: " << BMI << "." << std::endl;

  return 0;
}
