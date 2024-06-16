#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "game.h"


// builds the player struct with user input
Player build_player() {
  Player player;
  // TODO: build the player
  return player;
}

// UTILITY FUNCTION
void slow_print(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(10000);
  }
  putchar('\n');
}

