#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// CONSTANTS ==========================
int ENEMIES = 5;
int ENEMY_HEALTH_MIN = 5;
int ENEMY_HEALTH_MAX = 9;

// GAME FUNCTIONS =====================
Player init_player() {
  Player player;
  // TODO: use scanf to find input player stats
  return player;
}

Enemy *init_enemies() {
  Enemy *enemies = calloc(ENEMIES, sizeof(Enemy));
  for (int i = 0; i < ENEMIES; i++) {
    Enemy enemy;
    enemy.health =
        (rand() % (ENEMY_HEALTH_MAX - ENEMY_HEALTH_MIN)) + ENEMY_HEALTH_MIN;
    enemies[i] = enemy;
  }
  return enemies;
};

void play(Player player, Enemy *enemies) {
  // TODO: implement game loop
}

// UTILITY FUNCTIONS ====================
void slow_print(char *str) { slow_print_2(str, 10000); }

void slow_print_2(char *str, size_t speed) {
  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(speed);
  }
  putchar('\n');
}

void print_battle(Player player, Enemy enemy) {
  char player_health_line[1024], player_attack_enemy_health_line[1024],
      player_def_line[1024];

  sprintf(player_health_line,
          "+   Health:   %d               + »»------► +----+----+----+----+----+",
          player.health);
  sprintf(player_attack_enemy_health_line,
          "+   Attack:   %d               +           +    Health:   %d        +",
          player.attack, enemy.health);
  sprintf(player_def_line,
          "+   Defense:  %d               +           +----+----+----+----+----+",
          player.defence);

  slow_print_2("+----+----+----+----+----+----+ ", 5000);
  slow_print_2(
      "+        Player               +           +----+----+----+----+----+",
      5000);
  slow_print_2(
      "+----+----+----+----+----+----+           +        Enemy           +",
      5000);
  slow_print_2(player_health_line, 5000);
  slow_print_2(player_attack_enemy_health_line, 5000);
  slow_print_2(player_def_line, 5000);
  slow_print_2("+----+----+----+----+----+----+ ", 5000);
}

// TODO: utility for
// Battle ## :
// Here are your current stats:
// PLAYER STATS
// Increase??

// and

// You have killed enemy_##
// There are ## enemies left
// Do you wish to flee??

