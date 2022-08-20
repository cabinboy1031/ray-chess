#include "grid.h"

Vector2 to_screen(Grid_s grid, Vector2 coord) {
  if (coord.x + 1 > grid.bounds.x) {
    coord.x = grid.bounds.x - 1;
  }
  if (coord.y + 1 > grid.bounds.y) {
    coord.y = grid.bounds.y - 1;
  }
  if (coord.x < 0) {
    coord.x = 0;
  }
  if (coord.y < 0) {
    coord.y = 0;
  }

  return (Vector2){(((int)coord.x) * grid.cell_size) + grid.offset.x,
                   (((int)coord.y) * grid.cell_size) + grid.offset.y};
}

Vector2 to_grid(Grid_s grid, Vector2 coord) {
  return (Vector2){((int)(coord.x - grid.offset.x) / (int)grid.cell_size),
                   ((int)(coord.y - grid.offset.y) / (int)grid.cell_size)};
}
