#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "game.h"


Player init_player() {
  // TODO: implement this
  Player player;
  return player;
}

Enemy* init_enemies() {
  // TODO: implement this
  Enemy* enemies = NULL;
  return enemies;
};

// UTILITY FUNCTION
void slow_print(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(10000);
  }
  putchar('\n');
}

