#ifndef GAME
#define GAME

#include <stddef.h>
typedef struct player {
  int attack;
  int defence;
  int health;
} Player;

typedef struct enemy {
  int health;
} Enemy;

// GAME FUNCTIONS =====================
Player init_player();
Enemy *init_enemies();
void play(Player, Enemy *);
int get_enemy_attack();

// UTILITY FUNCTIONS ==================
void slow_print(char str[]);
void slow_print_2(char str[], size_t speed);
void print_battle(Player player, Enemy enemy);

#endif // !GAME
