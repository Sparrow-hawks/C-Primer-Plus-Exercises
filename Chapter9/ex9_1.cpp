// Book:      C++ Primer Plus
// Chapter:   9
// Exercise:  1

#include <iostream>
#include "golf.h"

const size_t Max = 5;

int main() {

  Golf players[Max];

  setgolf(players[0], "Sheldon Cooper", 10);
  setgolf(players[1], "Leonard Hofstader", 15);

  size_t numberOfPlayers = 2;
  for (size_t i = 2; i < 5; ++i, ++numberOfPlayers) {
    if (!setgolf(players[i]))
      break;
  }

  for (size_t i = 0; i < numberOfPlayers; ++i)
    showgolf(players[i]);

  for (size_t i = 0; i < numberOfPlayers; ++i)
    handicap(players[i], 100);

  showgolf(players[0]);

  return 0;
}
