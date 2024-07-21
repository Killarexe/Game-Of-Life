#include "game_settings.h"

#include <stdlib.h>

GameSettings* create_game_settings(int window_width, int window_height, int pixel_scale) {
  GameSettings* settings = malloc(sizeof(struct GameSettings));
  settings->window_width = window_width;
  settings->window_height = window_height;
  settings->pixel_scale = pixel_scale;
  return settings;
}

void free_game_settings(GameSettings *settings) {
  free(settings);
}
