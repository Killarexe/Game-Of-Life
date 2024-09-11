#include "cells_map.h"
#include "game.h"
#include <raylib.h>

int main() {
  Game game;
  init_game(&game);
  while (!WindowShouldClose()) {
    update_game(&game, GetFrameTime());
    BeginDrawing();
    render_game(&game);
    EndDrawing();
  }
  free_cells_map(game.map);
  return 0;
}
