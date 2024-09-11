#ifndef GAME_H
#define GAME_H

#include "cells_map.h"

typedef struct Game {
  CellsMap* map;
  int window_width;
  int window_height;
  int pixel_scale;
  int target_freq;
  int is_paused;
  float current_time;
} Game;

Game* init_game(Game* game);

void update_game(Game* game, float delta);

void render_game(Game* game);

#endif
