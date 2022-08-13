#pragma once
#include <raylib.h>
#include "board.h"

/** A simple structure which contains all the data of a chess move

    Given the nature of the program, the same function applies to every move,
    therefore, there does not need to be a command function encoded into the structure.

    The initial coordinate is used for the board itself to know what piece is needed to move.
    The transform is used as an offset. This means that the coordinate of a specific unit can be
    traced by simple transforms alone from move 0 to the end of the game.

    Captured pieces need to be recorded in order to place them back onto the board if a
    move which captures a piece is undone.
 */
typedef struct Move_s {
  Vector2 initial;
  Vector2 transform;
  Piece_s captured; // optional
} Move_s;
