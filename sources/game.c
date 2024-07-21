#include "game.h"
#include "cells_map.h"
#include "game_settings.h"

#include <time.h>
#include <stdlib.h>

#include <raylib.h>

Game* init_game() {
  Game* game = malloc(sizeof(struct Game));
  GameSettings* settings = create_game_settings(720, 720, 4);
  game->settings = settings;

  int map_width = settings->window_width / settings->pixel_scale;
  int map_height = settings->window_height / settings->pixel_scale;
  game->map = create_cells_map(map_width, map_height);
  SetRandomSeed(time(NULL));
  fill_with_random_cells(game->map);

  InitWindow(settings->window_width, settings->window_height, "Game of Life");

  return game;
}

void update_game(Game *game, float delta) {
  update_cells_map(game->map);
  delta = 0;
}

void render_game(Game *game) {
  draw_cells_map(game->map, game->settings);
}

void stop_game(Game *game) {
  free_cells_map(game->map);
  free(game);
}
