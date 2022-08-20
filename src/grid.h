#pragma once
#include <raylib.h>

typedef struct Grid_s {
  float cell_size;
  Vector2 offset;
  Vector2 bounds;
} Grid_s;

/** TODO unimplemented
   converts a grid coordinate to its respective screen coordinate.
   the screen coordinate will always land on the upper left corner of the grid cell
   @param grid the current grid settings
   @param coord the normalized grid coordinates
   @return Vector2 a point on the screen
 */
Vector2 to_screen(Grid_s grid, Vector2 coord);

/** TODO unimplemented
   converts a screen coordinate to the coordinate of the cell where the point lies
   @param grid the current grid settings
   @param coord the normalized grid coordinates
   @return Vector2 a grid cells coordinate
 */
Vector2 to_grid(Grid_s grid, Vector2 coord);
