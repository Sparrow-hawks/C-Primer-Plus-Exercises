#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "deck.h"

class Person {
private:
  std::string m_Name;
protected:

public:
  Person() : m_Name("None") {}
  Person(std::string& name) : m_Name(name) {}
  virtual ~Person();

  virtual void Get();
  virtual void Set() = 0;
  virtual void Show() const;
};

class Gunslinger : virtual public Person {
private:
  double m_DrawTime;
  int m_GunNotches;
protected:
  double Draw() const;
public:
  Gunslinger() : Person(), m_DrawTime(0.0), m_GunNotches(0) {}
  Gunslinger(const Person& ps, double drawTime, int gunNotches = 0) :
    Person(ps), m_DrawTime(drawTime), m_GunNotches(gunNotches) {}
  Gunslinger(std::string& name, double drawTime, int gunNotches = 0) :
    Person(name), m_DrawTime(drawTime), m_GunNotches(gunNotches) {}

  void Set();
  void Get();
  void Show() const;
};

class PokerPlayer : virtual public Person {
private:

protected:
  Card Draw() const;
public:
  PokerPlayer() : Person() {}
  PokerPlayer(std::string& name) : Person(name) {}
  PokerPlayer(const Person& ps) : Person(ps) {}

  void Set();
  void Show() const;
};

class BadDude : virtual public Gunslinger, virtual public PokerPlayer {
private:

protected:

  double Gdraw() const;
  Card Cdraw() const;
public:
  BadDude(){}
  BadDude(std::string& name, double drawTime, int gunNotches = 0) :
    Person(name), Gunslinger(name, drawTime, gunNotches), PokerPlayer(name) {}
  BadDude(const Person& ps, double drawTime, int gunNotches = 0) :
    Person(ps), Gunslinger(ps, drawTime, gunNotches), PokerPlayer(ps) {}
  BadDude(const Gunslinger& gs) :
    Person(gs), Gunslinger(gs), PokerPlayer(gs) {}
  BadDude(const PokerPlayer& pp, double drawTime, int gunNotches = 0) :
    Person(pp), Gunslinger(pp, drawTime, gunNotches), PokerPlayer(pp) {}

  void Set();
  void Show() const;
};
#endif
