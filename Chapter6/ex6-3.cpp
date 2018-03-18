// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  3

#include <iostream>

int main() {

  std::cout << "r) roślinożerca     p) pianista" << std::endl;
  std::cout << "d) drzewo           g) gra" << std::endl;

  char ch;
  do {
    std::cout << "Proszę podać literę r, p, d lub g: ";
    std::cin.get(ch);
    std::cin.get();
  } while (ch != 'r' && ch != 'p' && ch != 'd' && ch != 'g');

  switch(ch) {
    case 'p':
      std::cout << "Fryderyk Chopin to znany pianista.";
      break;
    case 'r':
      std::cout << "Miś koala to roślinożerca.";
      break;
    case 'd':
      std::cout << "Klon jest drzewem.";
      break;
    case 'g':
      std::cout << "Wiedźmin to najlepsza gra roku 2015.";
      break;
  }
  std::cout << std::endl;

  return 0;
}
