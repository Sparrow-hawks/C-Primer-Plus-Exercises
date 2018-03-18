// Book:      C++ Primer Plus
// Chapter:   5
// Exercise:  8

#include <iostream>
#include <cstring>

const unsigned int wordSize {80};
const char *endWord = "gotowe";

int main(void) {

  char word[wordSize];

  std::cout << "Podawaj słowa (kiedy skończysz, napisz \"" << endWord << "\")" << std::endl;

  //Word counter
  unsigned int wc = 0;
  do {
    ++wc;
    std::cin.get(word, wordSize, ' ').get();
  } while (strcmp(word, endWord));

  std::cout << "Podano " << wc - 1 << " słów." << std::endl;

  return 0;
}
