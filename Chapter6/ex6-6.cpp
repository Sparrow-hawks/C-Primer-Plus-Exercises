// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  6

#include <iostream>
#include <string>

const double donationTreshold = 10000;

int main(void) {

  size_t numberOfDonors;

  std::cout << "Podaj liczbę darczyńców: ";
  std::cin >> numberOfDonors;
  std::cin.get();

  struct Donor {
    std::string name;
    double donation;
  };

  Donor *donors = new Donor[numberOfDonors];

  for (size_t i = 0; i < numberOfDonors; ++i) {
    std::cout << "Podaj nazwisko darczyńcy: ";
    std::getline(std::cin, donors[i].name);
    std::cout << "Podaj wysokość datku: ";
    std::cin >> donors[i].donation;
    std::cin.get();
  }

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
