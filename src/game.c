// [GAME.C]
// This program was written by <YOUR-NAME-HERE>
// on <INSERT-DATE-HERE>

// A program that initialises our player, and runs the game loop!

// IMPORTS ====================================================================
// [DO NOT TOUCH]
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// CONSTANTS =================================================================
int ENEMIES = 5;
int ENEMY_HEALTH_MIN = 5;
int ENEMY_HEALTH_MAX = 9;
int ENEMY_ATTACK_MIN = 3;
int ENEMY_ATTACK_MAX = 8;
int STAT_INCREASE = 2;

// GAME FUNCTIONS =============================================================
/*
  [play]
  This is where the logic for the main game loop lives.
  Given a player and a list of enemies, start the duelling!
*/
void play(Player player, Enemy *enemies) {
  for (int i = 0; i < ENEMIES; i++) {
    Enemy enemy = enemies[i];

    // Battle Stats
    printf("\n\n\033[0;33m· · ────── Battle #%d ────── · ·\e[0m\n\n", i + 1);
    slow_print("\033[1m> Here are your current stats: \e[0m\n");
    printf("\tAttack: %d\n\tDefence: %d\n\tHealth: %d\n\n", player.attack,
           player.defence, player.health);

    // Increase Stats
    slow_print("\033[2mWhat would you like to do? Heal (h), Increase Attack (a) or "
               "Increase Defence (d)\e[0m");

    char stat;
    scanf("%c", &stat);
    while (stat != 'h' && stat != 'a' && stat != 'd') {
      slow_print("\n\033[1m> Pick your move: \e[0m");
      scanf(" %c", &stat);
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
        printf("\033[1;32mYou have killed enemy %d!\e[0m\n", i);
        continue;
      }

      // Enemy attacks player
      int enemy_attack = get_enemy_attack(enemy.level);
      int damage = enemy_attack - player.defence;
      if (damage < 0) {
        // Cannot deal less than 0 damage
        damage = 0;
      }

      printf("The enemy attacks you and deals %d damage\n", damage);
      player.health -= damage;
      printf("You now have %d health\n", player.health);
      if (player.health <= 0) {
        slow_print("\n\033[1;31mYOU DIED :(\e[0m");
        return;
      }
    }
  }
  slow_print("\n\033[1;33mENEMIES SLAIN !!\e[0m");
}

// HELPER FUNCTIONS ===========================================================
/*
  [init_player]
  Initialises and creates our player with strength, defence and health
*/
Player init_player() {
  Player player;

  slow_print("\033[1;37m> Enter your attack strength (max 5):\e[0m");
  scanf("%d", &player.attack);
  while (player.attack > 5 || player.attack < 0) {
    slow_print("\033[2mPlease enter a positive number up to 5\e[0m");
    scanf(" %d", &player.attack);
  }

  slow_print("\033[1;37m> Enter your defence strength (max 4):\e[0m");
  scanf("%d", &player.defence);
  while (player.defence > 4 || player.defence < 0) {
    slow_print("\033[2mPlease enter a positive number up to 4\e[0m");
    scanf(" %d", &player.defence);
  }

  slow_print("\033[1;37m> Enter your starting health (max 8):\e[0m");
  scanf("%d", &player.health);
  while (player.health > 8 || player.health < 0) {
    slow_print("\033[2mPlease enter a positive number up to 8\e[0m");
    scanf(" %d", &player.health);
  }

  return player;
}

/*
  [init_enemies]
  Creates an enemy with a level from 0 to ENEMIES, with random amount of health 
  between ENEMY_HEALTH_MIN and ENEMY_HEALTH_MAX, plus enemy level
*/
Enemy *init_enemies() {
  Enemy *enemies = calloc(ENEMIES, sizeof(Enemy));
  for (int i = 0; i < ENEMIES; i++) {
    Enemy enemy;
    enemy.level = i;
    enemy.health =
        (rand() % (ENEMY_HEALTH_MAX - ENEMY_HEALTH_MIN)) 
          + ENEMY_HEALTH_MIN 
          + enemy.level;
    enemies[i] = enemy;
  }
  return enemies;
};

/*
  [get_enemy_attack]
  Returns a random value of raw attack that the enemy deals to the player, between
  ENEMY_ATTACK_MIN and ENEMY_ATTACK_MAX, plus level
*/
int get_enemy_attack(int level) {
  return (rand() % (ENEMY_ATTACK_MAX - ENEMY_ATTACK_MIN)) 
    + ENEMY_ATTACK_MIN 
    + level;
}

// UTILITY FUNCTIONS ==========================================================
/*
  [print_battle]
  Given a player and Enemy, print their current stats in this round of battle!
*/
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

/*
  [slow_print]
  Given a string, prints it out character by character
*/
void slow_print(char *str) { slow_print_2(str, 10000); }

/*
  [slow_print_2]
  Prints out a string letter by letter at a given speed
*/
void slow_print_2(char *str, size_t speed) {
  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(speed);
  }
  putchar('\n');
}
