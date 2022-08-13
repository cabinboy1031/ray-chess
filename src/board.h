#pragma once
#include <raylib.h>
#include "grid.h"

/**
   The chess board. Theoretically any other board game as well.
   The board is encoded using characters, these characters are then
   compared to a map to get its respective object data
   in order to give the full range of possible pieces.

   The size of the board is defined as such,
   (grid width) * (grid height) * (defining piece characteristics)

   so a chess board would be a size of 64 * 2,
   where the two characteristics of a chess piece are:
   its team (black, white) and
   its type (rook, pawn, etc.)

   each characteristic is defined by a single byte,
   these bytes DO have to be unique in its own characteristic
   these bytes DO NOT have to be unique across characteristics

   so a unit on a board can be a black bishop 'bb' for example,
   but you cannot add a blue team bishop and a black team bishop
   without making them unique characters ('bb', 'Bb')

   this is simply for ease of computation and definition,
   given that these piece "names" are only used in code logic, they dont have to be
   mnemonically relevant, simply consistent across two versions of the game.
   Any alphanumeric character can be used as a characteristic in the board.

   Anything that requires more than 256 characteristics(or 54 for that matter) should probably just use
   an int anyways and an object pool of some sort.
 */
typedef struct Board_s {
  char *data;
  int size;
  Grid_s grid;
} Board_s;

// TODO board serialization, grid coordinate system, and board rendering

/**
   Example of a piece with two bytes defining its role and team
   An array of pieces will be converted into a map using the role and team in the struct.
 */
typedef struct Piece_s {
  char role;
  char team;
  Image *img_b;
  Image *img_w;
} Piece_s;

// TODO array to map conversion, map access, and image loading functions
