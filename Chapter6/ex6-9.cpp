// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  6

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const double donationTreshold = 10000;

int main(void) {

  size_t numberOfDonors;
  std::ifstream inFile;
  inFile.open("Donators.txt");
  if (!inFile.is_open()) {
    std::cerr << "Błąd otwarcia pliku." << std::endl;
    exit(EXIT_FAILURE);
  }

  inFile >> numberOfDonors;
  inFile.get();

  struct Donor {
    std::string name;
    double donation;
  };

  Donor *donors = new Donor[numberOfDonors];

  for (size_t i = 0; i < numberOfDonors; ++i) {
    std::getline(inFile, donors[i].name);
    inFile >> donors[i].donation;
    inFile.get();
  }

  inFile.close();

  unsigned int count = 0;
  std::cout << "Nasi wspaniali sponsorzy:" << std::endl;
  for (size_t i = 0; i < numberOfDonors; ++i) {
    if (donors[i].donation >= donationTreshold) {
      std::cout << donors[i].name << ": " << donors[i].donation << " zł." << std::endl;
      ++count;
    }
  }
  if (!count)
    std::cout << "Brak" << std::endl;

  count = 0;
  std::cout << "Nasi sponsorzy:" << std::endl;
  for (size_t i = 0; i < numberOfDonors; ++i) {
    if (donors[i].donation < donationTreshold) {
      std::cout << donors[i].name << ": " << donors[i].donation << " zł." << std::endl;
      ++count;
    }
  }
  if (!count)
    std::cout << "Brak" << std::endl;

  delete[] donors;

  return 0;
}
