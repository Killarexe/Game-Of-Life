#include "game.h"
#include <raylib.h>

int main() {
  Game* game = init_game();

  while (!WindowShouldClose()) {
    update_game(game, GetFrameTime());
    BeginDrawing();
    render_game(game);
    EndDrawing();
  }

  stop_game(game);
  return 0;
}
