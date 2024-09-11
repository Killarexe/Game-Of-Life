#include "game.h"
#include "cells_map.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <raylib.h>

Game* init_game(Game* game) {
  game->window_width = 720;
  game->window_height = 720;
  game->pixel_scale = 4;
  int map_width = game->window_width / game->pixel_scale;
  int map_height = game->window_height / game->pixel_scale;

  game->map = create_cells_map(map_width, map_height);
  SetRandomSeed(time(NULL));
  fill_with_random_cells(game->map);

  game->target_freq = 60;
  game->is_paused = 0;
  game->current_time = 0.0f; 

  InitWindow(game->window_width, game->window_height, "Game of Life");
  return game;
}

void update_game(Game *game, float delta) {
  if (game->is_paused == 0) {
    if (IsKeyDown(KEY_UP)) {
      game->target_freq++;
    }
    if (IsKeyDown(KEY_DOWN)) {
      game->target_freq--;
    }
    if (IsKeyPressed(KEY_LEFT_CONTROL)) {
      game->is_paused = 1;
    }
    if (IsKeyPressed(KEY_ENTER)) { 
      fill_with_random_cells(game->map);
    }
    game->target_freq = game->target_freq < 1 ? 1 : game->target_freq;
    if (game->current_time > (1.0f / (float)game->target_freq)) {
      update_cells_map(game->map);
      game->current_time = 0.0F;
    } else {
      game->current_time += delta;
    }
  } else {
    game->current_time = 0.0f;
    if (IsKeyPressed(KEY_ENTER)) {
      update_cells_map(game->map);
    } else if (IsKeyPressed(KEY_LEFT_CONTROL)) {
      game->is_paused = 0;
    }
  }
  delta = 0;
}

void render_game(Game *game) {
  draw_cells_map(game->map, game->pixel_scale);
  if (game->is_paused == 0) {
    char speed[18];
    sprintf(speed, "Run Mode\nSpeed: %d", game->target_freq);
    DrawText(speed, 10, 10, 24, GREEN);
  } else {
    DrawText("Pause Mode\nPress CTRL to stop pause mode.", 10, 10, 24, RED);
  }
}
