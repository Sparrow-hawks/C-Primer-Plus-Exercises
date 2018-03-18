#include <cstdlib>
#include <ctime>
#include <cstring>

#include "deck.h"

const char* Card::s_ColorNames[COLORS] = {
  "Heart", "Tile", "Clover", "Pike"
};

const char* Card::s_FigureNames[FIGURES] = {
  "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
  "Jack", "Queen", "King"
};

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << "{" << card.s_FigureNames[card.m_Figure] << " " << card.s_ColorNames[card.m_Color] << "}";

  return os;
}

Deck::Deck() : m_InTheDeck (SIZE) {
  srand(time(0));

  for (size_t i = 0; i < Card::COLORS; ++i)
    std::memset(m_DeckOfCards[i], Card::FIGURES, 1);
}

Deck::~Deck() {

}

Card Deck::get() {
  Card card {-1, Card::heart};
  if (m_InTheDeck != 0) {
    int c, f;
    do {
      c = rand() % Card::COLORS;
      f = rand() % Card::FIGURES;
    } while(m_DeckOfCards[c][f] != 0);
    m_DeckOfCards[c][f] = 1;
    --m_InTheDeck;
    card = Card{f, (Card::Color)c};
  } else {
    std::cout << "Deck is empty!" << std::endl;
  }
  return card;
}

void Deck::shuffle() {
  m_InTheDeck = SIZE;

  for (size_t i = 0; i < Card::COLORS; ++i)
    std::memset(m_DeckOfCards[i], Card::FIGURES, 1);
}

void Deck::ret(const Card& card) {
  if (m_InTheDeck < SIZE) {
    int c = card.m_Color;
    int f = card.m_Figure;

    if (m_DeckOfCards[c][f] == 0) {
      m_DeckOfCards[c][f] = 1;
      ++m_InTheDeck;
    }
  }
}
