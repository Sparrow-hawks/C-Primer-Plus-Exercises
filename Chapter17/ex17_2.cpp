// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  2

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

  using namespace std;

  if (argc != 2) {
    std::cerr << "Wrong argument list!\n";
    exit(EXIT_FAILURE);
  }

  ofstream outFile (argv[1], std::ios_base::out);

  if (!outFile.is_open()) {
    std::cerr << "Can't create file!\n";
    exit(EXIT_FAILURE);
  }

  cout << "Enter text: ";
  char c;
  while (std::cin.get(c) && outFile.good())
    outFile.put(c);

  outFile.close();

  return 0;
}
