#include <stdio.h>
#include <string.h>
#include "game.h"

// Entry point
int main(void) {
  // Intro message
  slow_print("Welcome to pokemon (or something like that)\n");
  Player player = init_player();
  Enemy* enemy = init_enemies();
  // TODO: fill in based on the spec
}

