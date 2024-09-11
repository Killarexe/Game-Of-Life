#ifndef CELLS_MAP_H
#define CELLS_MAP_H

#define floordiv(a, b) ({                                           \
    int result;                                                     \
    asm("mov %%eax, %%edx; sub %1, %%edx; add $1, %%edx;"           \
        "test %%eax, %%eax; cmovs %%edx, %%eax; cltd;"              \
        "idivl %1;"                                                 \
        : "=a" (result)                                             \
        : "r" (b),                                                  \
          "0" (a)                                                   \
        : "rdx");                                                   \
    result;})

typedef struct CellsMap {
  int width;
  int height;
  char* current_cells;
  char* first_cells;
  char* second_cells;
} CellsMap;

CellsMap* create_cells_map(int width, int height);

void set_cell_at_pos(CellsMap* map, int x, int y, char value);

void fill_with_random_cells(CellsMap* map);

void fill_cells_map(CellsMap* map, char value);

void update_cells_map(CellsMap* map);

void draw_cells_map(CellsMap* map, int pixel_scale);

void free_cells_map(CellsMap* map);

#endif
