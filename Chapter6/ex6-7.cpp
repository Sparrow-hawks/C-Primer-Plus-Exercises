// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  7

#include <iostream>
#include <cctype>
#include <cstring>

const char* vovels = "aeiuo";

int main(void) {

  std::cout << "Podawaj słowa (pojedyńcze q kończy):" << std::endl;

  size_t vovelWords = 0;
  size_t nonVovelWords = 0;
  size_t otherWords = 0;

  bool inWord = false;
  while (1) {
    char ch;
    std::cin.get(ch);
    if (ch == 'q')
      break;

    if (isalpha(ch)) {
      if (!inWord) {
        if (memchr(vovels, ch, strlen(vovels)) != NULL)
          ++vovelWords;
        else
          ++nonVovelWords;
      }
      inWord = true;
    } else if (isdigit(ch)) {
      if (!inWord) {
        ++otherWords;
      }
      inWord = true;
    } else if (isspace(ch)) {
      inWord = false;
    }
  }

  std::cout << nonVovelWords << " słów zaczyna się od spółgłosek." << std::endl;
  std::cout << vovelWords << " słów zaczyna się od samogłosek." << std::endl;
  std::cout << otherWords << " słów nie zalicza się do żadnej z tych kategorii." << std::endl;

  return 0;
}
