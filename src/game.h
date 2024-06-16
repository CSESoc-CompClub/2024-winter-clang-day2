#ifndef GAME
#define GAME

typedef struct player {
  int attack;
  int defence;
  int health;
} Player;

typedef struct enemy {
  int attack;
  int defence;
  int health;
} Enemy;

// GAME FUNCTIONS ===================== 
Player init_player();
Enemy* init_enemies();
// TODO: add the rest of the game functions

// UTILITY FUNCTIONS ================== 
void slow_print(char str[]);

#endif // !GAME
