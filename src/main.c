#include <stdio.h>
#include <string.h>
#include "game.h"

// Entry point
int main(void) {
  slow_print("Welcome to pokemon (or something like that)\n");
  Player player = init_player();
  Enemy* enemies = init_enemies();
  play(player, enemies);
}

