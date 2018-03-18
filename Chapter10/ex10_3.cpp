// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  3

#include <iostream>
#include "golf.h"

const size_t Max = 5;

int main() {
  Golf players[Max] = {
    Golf("Sheldon Cooper", 10),
    Golf("Leonard Hofstader", 15),
  };

  size_t numberOfPlayers = 2;
  for (size_t i = 2; i < Max; ++numberOfPlayers) {
    if (!players[i].set())
      break;
  }

  for (size_t i = 0; i < numberOfPlayers; ++i)
    players[i].show();

  for (size_t i = 0; i < numberOfPlayers; ++i)
    players[i].handicap(100);

  players[0].show();

  return 0;
}
