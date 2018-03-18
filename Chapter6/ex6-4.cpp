// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  4

#include <iostream>

int main(void) {

  const size_t strsize {80};
  //struktura imion Zakonu Programistów Dobrej Woli
  struct ZPDW {
    char name[strsize];
    char position[strsize];
    char anonymzpdw[strsize];
    int preferencies;
  };

  enum {name, position, anonym};

  ZPDW zpdw[5] {
    {"Wimp Macho", "Developer", "WAMP", name},
    {"Raki Rhodes", "Młodszy programista", "RR", position},
    {"Celia Laiter", "Rysownik", "MIPS", anonym},
    {"Hoppy Hipman", "Szkoleniowiec analityków", "HIPPO", position},
    {"Pat Hand", "Starszy programista", "LOOPY", anonym},
  };

  std::cout << "Zakon Programistów Dobrej Woli" << std::endl;
  std::cout << "a. lista wg imion         b. lista wg stanowisk" << std::endl;
  std::cout << "c. lista wg pseudonimów   d. lista wg preferencji" << std::endl;
  std::cout << "q. koniec" << std::endl;

  char ch;
  bool exit = false;
  while (!exit) {
    do {
      std::cout << "Wybierz jedną z opcji: ";
      std::cin >> ch;
    } while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'q');
    switch (ch) {
      case 'a':
        for (size_t i = 0; i < sizeof (zpdw) / sizeof (ZPDW); ++i) {
          std::cout << zpdw[i].name << std::endl;
        }
        break;
      case 'b':
        for (size_t i = 0; i < sizeof (zpdw) / sizeof (ZPDW); ++i) {
          std::cout << zpdw[i].position << std::endl;
        }
        break;
      case 'c':
        for (size_t i = 0; i < sizeof (zpdw) / sizeof (ZPDW); ++i) {
          std::cout << zpdw[i].anonymzpdw << std::endl;
        }
        break;
      case 'd':
        for (size_t i = 0; i < sizeof (zpdw) / sizeof (ZPDW); ++i) {
          switch (zpdw[i].preferencies) {
            case name:
              std::cout << zpdw[i].name << std::endl;
              break;
            case position:
              std::cout << zpdw[i].position << std::endl;
              break;
            case anonym:
              std::cout << zpdw[i].anonymzpdw << std::endl;
              break;
          }
        }
        break;
      case 'q':
        exit = true;
        std::cout << "Do zobaczenia!" << std::endl;
        break;
    }
  }

  return 0;
}
