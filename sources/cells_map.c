#include "cells_map.h"
#include "game_settings.h"

#include <stdlib.h>
#include <math.h>

#include <raylib.h>

CellsMap* create_cells_map(int width, int height) {
  CellsMap* map = malloc(sizeof(struct CellsMap));
  map->width = width;
  map->height = height;
  map->cells = malloc(sizeof(char) * width * height);
  return map;
}

void set_cell_at_pos(CellsMap *map, int x, int y, char value) {
  int index = x * y;
  if (index < map->width * map->height) {
    map->cells[index] = value;
  }
}

void fill_with_random_cells(CellsMap *map) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    map->cells[i] = GetRandomValue(0, 1);
  }
}

void fill_cells_map(CellsMap *map, char value) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    map->cells[i] = value;
  }
}

void update_cells_map(CellsMap *map) {
  int map_size = map->width * map->height;
  char* new_cells = malloc(sizeof(char) * map_size);
  for (int index = 0; index < map_size; index++) {
    char value = map->cells[index];
    int x = index % map->width;
    int y = floor((double)index / map->width);
    int live_cells = 0;
    for (int x_offset = -1; x_offset < 2; x_offset++) {
      int x_pos = x + x_offset;
      for (int y_offset = -1; y_offset < 2; y_offset++) {
        int y_pos = y + y_offset;
        int cell_index = x_pos * y_pos;
        if (cell_index < map_size && (x_pos != y_pos || x_offset != 0)) {
          if (map->cells[cell_index] == 1) {
            live_cells++;
          }
        }
      }
    }
    if (value == 1 && (live_cells == 2 || live_cells == 3)) {
      new_cells[index] = 1;
    } else if (live_cells == 3) {
      new_cells[index] = 1;
    } else {
      new_cells[index] = 0;
    }
  }
  free(map->cells);
  map->cells = new_cells;
}

void draw_cells_map(CellsMap* map, GameSettings* settings) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    char value = map->cells[i];
    int x = i % map->width;
    int y = floor((double)i / map->width);
    DrawRectangle(x * settings->pixel_scale, y * settings->pixel_scale, settings->pixel_scale, settings->pixel_scale, value == 1? WHITE : BLACK);
  }
}

void free_cells_map(CellsMap *map) {
  free(map->cells);
  free(map);
}
