#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "game.h"


// CONSTANTS ==========================
int ENEMIES = 10;

// GAME FUNCTIONS =====================
Player init_player() {
  // TODO: implement this
  Player player;
  return player;
}

Enemy* init_enemies() {
  // TODO: implement this
  Enemy* enemies = calloc(ENEMIES, sizeof(Enemy));
  return enemies;
};

// UTILITY FUNCTIO ====================
void slow_print(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(10000);
  }
  putchar('\n');
}

