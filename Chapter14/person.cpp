#include <iostream>
#include "person.h"

// One deck for all players
Deck deck;

Person::~Person() {

}

void Person::Show() const {
  std::cout << m_Name << std::endl;
}

void Person::Get() {
  getline(std::cin, m_Name);
}

double Gunslinger::Draw() const {
  return m_DrawTime;
}

void Gunslinger::Show() const {
  Person::Show();
  std::cout << "Draw time: " << Draw() << ", Gun's notches: " << m_GunNotches << std::endl;
}

void Gunslinger::Get() {
  std::cout << "Enter draw time: ";
  std::cin >> m_DrawTime;
  std::cout << "Enter gun's notches: ";
  std::cin >> m_GunNotches;
  while (std::cin.get() != '\n')
    continue;
}

void Gunslinger::Set() {
  std::cout << "Enter gunslinger's name: ";
  Person::Get();
  Get();
}

Card PokerPlayer::Draw() const {
  return deck.get();
}

void PokerPlayer::Set() {
  std::cout << "Enter Pokerplayer's name: ";
  Person::Get();
}

void PokerPlayer::Show() const {
  Person::Show();
  std::cout << "Player has: " << Draw() << std::endl;
}

Card BadDude::Cdraw() const {
  return PokerPlayer::Draw();
}

double BadDude::Gdraw() const {
  return Gunslinger::Draw();
}

void BadDude::Set() {
  std::cout << "Enter BadDude's name: ";
  Person::Get();
  Gunslinger::Get();
}

void BadDude::Show() const {
  Person::Show();
  std::cout << "Player has: " << Cdraw() << std::endl;
  std::cout << "Draw time: " << Gdraw() << std::endl;
}
