// [MAIN.C]
// This program was written by <YOUR-NAME-HERE>
// on <INSERT-DATE-HERE>

// A program that initialises and runs our game.

// IMPORTS ====================================================================
// [DO NOT TOUCH]
#include <stdio.h>
#include <string.h>
#include "game.h"

// ============================================================================
int main(void) {
  // Prints intro message
  slow_print("\033[1;31mWelcome to ConkClub !! Time to du-du-duel >:D\e[0m\n");

  // Initialise
  Player player = init_player();
  Enemy* enemies = init_enemies();

  play(player, enemies);
}

