#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// CONSTANTS ==========================
int ENEMIES = 5;
int ENEMY_HEALTH_MIN = 5;
int ENEMY_HEALTH_MAX = 9;
int ENEMY_ATTACK_MIN = 3;
int ENEMY_ATTACK_MAX = 8;
int STAT_INCREASE = 2;

// GAME FUNCTIONS =====================
// TODO: the students implement this
void play(Player player, Enemy *enemies) {
  for (int i = 0; i < ENEMIES; i++) {
    Enemy enemy = enemies[i];

    // Battle Stats
    printf("\n\nBattle #%d:\n\n", i + 1);
    slow_print("Here are your current stats: \n");
    printf("Attack: %d\nDefence: %d\nHealth: %d\n\n", player.attack,
           player.defence, player.health);

    // Increase Stats
    slow_print("What would you like to do? Heal (h), Increase Attack (a) or "
               "Increase Defence (d): ");

    char stat;
    scanf("%c", &stat);
    while (stat != 'h' && stat != 'a' && stat != 'd') {
      slow_print("\nPlease select a correct option: ");
      scanf("%c", &stat);
    }

    if (stat == 'h') {
      player.health += STAT_INCREASE;
    } else if (stat == 'a') {
      player.attack += STAT_INCREASE / 2;
    } else {
      player.defence += STAT_INCREASE / 2;
    }

    // Print Battle
    while (enemy.health > 0 && player.health > 0) {
      printf("\n\n");
      print_battle(player, enemy);

      // Player attacks enemy
      printf("You attack the enemy and deal %d damage\n", player.attack);
      enemy.health -= player.attack;
      printf("The enemy has %d health\n", enemy.health);
      if (enemy.health <= 0) {
        printf("You have killed enemy %d!\n", i);
        continue;
      }

      // Enemy attacks player
      int enemy_attack = get_enemy_attack();
      int damage = enemy_attack - player.defence;
      if (damage < 0) {
        // Cannot deal less than 0 damage
        damage = 0;
      }

      printf("The enemy attacks you and deals %d damage\n", damage);
      player.health -= damage;
      printf("You now have %d health\n", player.health);
      if (player.health <= 0) {
        slow_print("You died :(");
        return;
      }
    }
  }
}

// Implemented by CompClub
Player init_player() {
  Player player;

  slow_print("Enter your attack strength (max 5): ");
  scanf("%d", &player.attack);
  while (player.attack > 5 || player.attack < 0) {
    slow_print("Please enter a positive number up to 5");
    scanf("%d", &player.attack);
  }

  slow_print("Enter your defence strength (max 4): ");
  scanf("%d", &player.defence);
  while (player.defence > 4 || player.defence < 0) {
    slow_print("Please enter a positive number up to 4: ");
    scanf("%d", &player.defence);
  }

  slow_print("Enter your starting health (max 8): ");
  scanf("%d", &player.health);
  while (player.health > 8 || player.health < 0) {
    slow_print("Please enter a positive number up to 8: ");
    scanf("%d", &player.health);
  }

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

int get_enemy_attack() {
  return (rand() % (ENEMY_ATTACK_MAX - ENEMY_ATTACK_MIN)) + ENEMY_ATTACK_MIN;
}

void print_battle(Player player, Enemy enemy) {
  char player_health_line[1024], player_attack_enemy_health_line[1024],
      player_def_line[1024];

  sprintf(
      player_health_line,
      "+   Health:   %d               + »»------► +----+----+----+----+----+",
      player.health);
  sprintf(
      player_attack_enemy_health_line,
      "+   Attack:   %d               +           +    Health:   %d        +",
      player.attack, enemy.health);
  sprintf(
      player_def_line,
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
