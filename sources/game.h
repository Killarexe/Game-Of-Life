#ifndef GAME_H
#define GAME_H

#include "cells_map.h"
#include "game_settings.h"

typedef struct Game {
  CellsMap* map;
  GameSettings* settings;
  int target_fps;
  int is_paused;
} Game;

Game* init_game();

void update_game(Game* game, float delta);

void render_game(Game* game);

void stop_game(Game* game);

#endif
