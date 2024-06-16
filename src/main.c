#include <stdio.h>
#include <string.h>
#include "game.h"

// Entry point
int main(void) {
  // Intro message
  slow_print(
      "Welcome to CyberNEx Corp candidate, today is your first day on the "
      "job and your final test, please check the file linked to neurochip. "
      "It includes all the information and details of mission REDACTED.\n");
  Player player = build_player();
  // TODO: fill in based on the spec
}

