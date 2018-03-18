// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  3

#include <iostream>
#include <string>
#include <cctype>

const std::string& upper(std::string& str);

int main(void) {

  std::string line;
  std::cout << "Podaj łańcuch (q, aby skończyć): ";
  while (std::getline(std::cin, line)) {
    if (line.length() == 1 && line.at(0) == 'q')
      break;
    else if (line.length() > 0) {
      std::cout << upper(line) << std::endl;
    }
    std::cout << "Następny łańcuch (q, aby skończyć): ";
    std::cout.flush();
  }
  std::cout << "Do widzenia!" << std::endl;

  return 0;
}

const std::string& upper(std::string& str) {
  for(auto it = str.begin(); it != str.end(); ++it) {
    *it = toupper(*it);
  }
  return str;
}
