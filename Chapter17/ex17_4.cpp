// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  4

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {

  if (argc != 4) {
    std::cerr << "[ERROR] Use: " << argv[0] << " {IN1} {IN2} {OUT}\n";
    exit(EXIT_FAILURE);
  }

  std::ifstream in1, in2;
  std::ofstream out;

  in1.open(argv[1], std::ios_base::in);
  if (!in1.is_open()) {
    std::cerr << "[ERROR] Can't open " << argv[1] << " file\n";
    exit(EXIT_FAILURE);
  }
  in2.open(argv[2], std::ios_base::in);
  if (!in2.is_open()) {
    std::cerr << "[ERROR] Can't open " << argv[2] << " file\n";
    exit(EXIT_FAILURE);
  }

  out.open(argv[3], std::ios_base::out);
  if (!out.is_open()) {
    std::cerr << "[ERROR] Can't open " << argv[3] << " file\n";
  }

  std::string line;
  while (!in1.eof() && !in2.eof()) {
    if (!in1.eof()) {
      std::getline(in1, line);

      out << line;
    }

    out << " ";

    if (!in2.eof()) {
      std::getline(in2, line);

      out << line;
    }
    out << std::endl;
  }

  in1.close();
  in2.close();
  out.close();

  return 0;
}
