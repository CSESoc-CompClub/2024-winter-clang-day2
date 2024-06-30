#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// CONSTANTS ==========================
int ENEMIES = 5;
int ENEMY_HEALTH_MIN = 5;
int ENEMY_HEALTH_MAX = 9;
int STAT_INCREASE = 5;

// GAME FUNCTIONS =====================
Player init_player() {
  Player player;
  // TODO: use scanf to find input player stats

  slow_print("Enter your attack strength: ");
  scanf("%d", &player.attack);

  slow_print("Enter your defence strength: ");
  scanf("%d", &player.defence);
  
  int health;
  slow_print("Enter your starting health (max 10): ");
  scanf("%d", &health);

  while (health > 10 || health < 0) {
    slow_print("Please enter a positive number up to 10: ");
    scanf("%d", &health);
  }
  player.health = health;
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

void battle_stats(Player player, int battle_number) {
  char battle_stats[1024], player_stats[1024];
  sprintf(battle_stats, "Battle #%d\n", battle_number);
  sprintf(player_stats, "Attack: %d\n Defence: %d\n Health: %d\n", player.attack, player.defence, player.health);
  
  slow_print(battle_stats);
  slow_print("Here are your current stats: \n");
  slow_print(player_stats);
  slow_print("What would you like to do? Heal (h), Increase Attack (a) or Increase Defence (d): ");
  
  char stat;
  scanf("%c", &stat);
  while (stat != 'h' && stat != 'a' && stat != 'd') {
    slow_print("\nPlease select a correct option: ");
  }

  if (stat == 'h') {
    player.health += STAT_INCREASE;
  } else if (stat == 'a') {
    player.attack += STAT_INCREASE;
  } else {
    player.defence += STAT_INCREASE;
  }
}

// and

// You have killed enemy_##
// There are ## enemies left
// Do you wish to flee??

