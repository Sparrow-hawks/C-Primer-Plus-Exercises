// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  3

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    std::cerr << "[ERROR] Use: " << argv[0] << " {IN} {OUT}\n";
    exit(EXIT_FAILURE);
  }

  std::ifstream inFile (argv[1], std::ios_base::in);
  std::ofstream outFile (argv[2], std::ios_base::out);

  if (!inFile.is_open()) {
    std::cerr << "[ERROR] Can't open source file.\n";
    exit(EXIT_FAILURE);
  }
  if (!outFile.is_open()) {
    std::cerr << "[ERROR] Can't open destination file.\n";
    exit(EXIT_FAILURE);
  }

  char c;
  while (inFile.get(c))
    outFile.put(c);

  inFile.close();
  outFile.close();

  std::cout << "*** COPY END ***" << std::endl;

  return 0;
}
