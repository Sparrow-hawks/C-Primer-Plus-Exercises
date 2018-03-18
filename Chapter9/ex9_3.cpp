// Book:      C++ Primer Plus
// Chapter:   9
// Exercise:  3

#include <iostream>
#include <cstring>
#include <new>

struct Chaf {
  char dross[20];
  int slag;
};

static char buffer[200];

int main() {

  std::cout << "Buffer address: " << &buffer << std::endl;

  Chaf *pChaf1 = new (buffer) Chaf[2];

  std::cout << "pChaf1 address: " << pChaf1 << std::endl;

  strncpy(pChaf1[0].dross, "Dross 1", 19);
  strncpy(pChaf1[1].dross, "Dross 2", 19);

  pChaf1[0].slag = 100;
  pChaf1[1].slag = 200;

  std::cout << "pChaf1[0] address: " << &pChaf1[0] << std::endl;
  std::cout << "pChaf1[1] address: " << &pChaf1[1] << std::endl;

  std::cout << std::endl;
  std::cout << "pChaf1[0]: " << pChaf1[0].dross << ", " << pChaf1[0].slag << std::endl;
  std::cout << "pChaf1[1]: " << pChaf1[1].dross << ", " << pChaf1[1].slag << std::endl;
  std::cout << std::endl;

  char *dbuffer = new char[200];

  std::cout << "Dynamic buffer address: " << dbuffer << std::endl;

  Chaf *pChaf2 = new (dbuffer) Chaf[2];

  std::cout << "pChaf2 address: " << pChaf2 << std::endl;

  strncpy(pChaf2[0].dross, "Droos 3", 19);
  strncpy(pChaf2[1].dross, "Dross 4", 19);

  pChaf2[0].slag = 300;
  pChaf2[1].slag = 400;

  std::cout << "pChaf2[0] address: " << &pChaf2[0] << std::endl;
  std::cout << "pChaf2[1] address: " << &pChaf2[1] << std::endl;

  std::cout << std::endl;
  std::cout << "pChaf2[0]: " << pChaf2[0].dross << ", " << pChaf2[0].slag << std::endl;
  std::cout << "pChaf2[1]: " << pChaf2[1].dross << ", " << pChaf2[1].slag << std::endl;
  std::cout << std::endl;

  delete[] pChaf2;

  return 0;
}
