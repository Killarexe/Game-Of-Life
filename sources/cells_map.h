#ifndef CELLS_MAP_H
#define CELLS_MAP_H

#include "game_settings.h"
typedef struct CellsMap {
  int width;
  int height;
  char* cells;
} CellsMap;

CellsMap* create_cells_map(int width, int height);

void set_cell_at_pos(CellsMap* map, int x, int y, char value);

void fill_with_random_cells(CellsMap* map);

void fill_cells_map(CellsMap* map, char value);

void update_cells_map(CellsMap* map);

void draw_cells_map(CellsMap* map, GameSettings* settings);

void free_cells_map(CellsMap* map);

#endif
