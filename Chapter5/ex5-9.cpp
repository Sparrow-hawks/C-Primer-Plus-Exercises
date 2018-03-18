// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  9

#include <iostream>
#include <string>

const std::string endWord = "gotowe";

int main(void) {

  std::cout << "Podawaj słowa (kiedy skończysz, napisz \"" << endWord << "\")" << std::endl;
  std::string word;
  //Word counter
  unsigned int wc = 0;
  do {
    ++wc;
    std::cin >> word;
  } while (word != endWord);

  std::cout << "Podano " << wc - 1 << " słów." << std::endl;

  return 0;
}
