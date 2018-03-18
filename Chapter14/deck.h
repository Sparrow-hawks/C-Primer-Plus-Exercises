#ifndef DECK_H
#define DECK_H

#include <iostream>

class Deck;

class Card {
  friend class Deck;
public:
  enum Color {
    heart, tile, clover, pike
  };

private:
  enum {
    COLORS = 4,
    FIGURES = 13,
  };

  int m_Figure;
  Color m_Color;

  static const char* s_ColorNames[COLORS];
  static const char* s_FigureNames[FIGURES];

public:
  Card() : m_Figure (1), m_Color(heart) { };
  Card(int f, Color c) : m_Figure (f), m_Color(c) {}

  friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

class Deck {
public:

private:
  enum {
    SIZE = 52,
  };

  int m_InTheDeck;
  int m_DeckOfCards[Card::COLORS][Card::FIGURES];

public:
  Deck();
  ~Deck();

  Card get();
  void ret(const Card& card);

  bool full() const {return m_InTheDeck == SIZE;}
  bool empty() const {return m_InTheDeck == 0;}
  void shuffle();
};

#endif
