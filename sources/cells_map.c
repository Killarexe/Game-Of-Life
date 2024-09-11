#include "cells_map.h"

#include <stdlib.h>
#include <raylib.h>
#include <time.h>

CellsMap* create_cells_map(int width, int height) {
  CellsMap* map = malloc(sizeof(struct CellsMap));
  map->width = width;
  map->height = height;
  map->first_cells = malloc(sizeof(char) * width * height);
  map->second_cells = malloc(sizeof(char) * width * height);
  map->current_cells = map->first_cells;
  return map;
}

void set_cell_at_pos(CellsMap *map, int x, int y, char value) {
  int index = x * y;
  if (index < map->width * map->height) {
    map->current_cells[index] = value;
  }
}

void fill_with_random_cells(CellsMap *map) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    map->current_cells[i] = GetRandomValue(0, 1);
  }
}

void fill_cells_map(CellsMap *map, char value) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    map->current_cells[i] = value;
  }
}


int get_live_cells_neighbours(CellsMap* map, int x, int y) {
  int live_cells = 0;
  for (int x_offset = -1; x_offset < 2; x_offset++) {
    int x_pos = x + x_offset;
    for (int y_offset = -1; y_offset < 2; y_offset++) {
      int y_pos = y + y_offset;
      int cell_index = y_pos * map->width + x_pos;
      if ((x_offset != y_offset || x_offset != 0) && map->current_cells[cell_index] == 1) {
          live_cells++;
      }
    }
  }
  return live_cells;
}

void update_cells_map(CellsMap *map) {
  int map_size = map->width * map->height;
  char* next_cells = NULL;
  if (map->current_cells == map->first_cells) {
    next_cells = map->second_cells;
  } else {
    next_cells = map->first_cells;
  }
  for (int index = 0; index < map_size; index++) {
    char value = map->current_cells[index];
    int x = index % map->width;
    int y = floordiv(index, map->width);
    int live_cells = get_live_cells_neighbours(map, x, y);
    if (value == 1 && (live_cells == 2 || live_cells == 3)) {
      next_cells[index] = 1;
    } else if (live_cells == 3) {
      next_cells[index] = 1;
    } else {
      next_cells[index] = 0;
    }
  }
  map->current_cells = next_cells;
}

void draw_cells_map(CellsMap* map, int pixel_scale) {
  int map_size = map->width * map->height;
  for (int i = 0; i < map_size; i++) {
    char value = map->current_cells[i];
    int x = i % map->width * pixel_scale;
    int y = floordiv(i, map->width) * pixel_scale;
    DrawRectangle(x, y, pixel_scale, pixel_scale, value == 1 ? WHITE : BLACK);
  }
}

void free_cells_map(CellsMap *map) {
  free(map->first_cells);
  free(map->second_cells);
  free(map);
}
