#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

typedef struct GameSettings {
  int window_width;
  int window_height;
  int pixel_scale;
} GameSettings;

GameSettings* create_game_settings(int window_width, int window_height, int pixel_scale);

void free_game_settings(GameSettings* settings);

#endif
