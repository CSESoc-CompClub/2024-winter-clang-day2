#ifndef GAME
#define GAME

typedef struct player {
  int age;
  int height;
  char name[];
  // TODO: add the rest
} Player;

// game functions
Player build_player();
// TODO: add the rest of the game functions

// utility
void slow_print(char str[]);

#endif // !GAME
