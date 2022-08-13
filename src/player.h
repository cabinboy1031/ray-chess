#pragma once
#include "board.h"
#include "move.h"

/** TODO add player and bot implementations
   The public interface, takes an implemented function
   and applies data given to it from actual player data like bot and commands
 */
typedef struct Player_s {
  const struct Player_i *player_i;
} Player_s;

struct Player_i {
  Move_s* (*get_move)(Board_s *board, struct Player_s *player);
};

static inline Move_s move_piece(Board_s *board, struct Player_s *player){
  Move_s *move = player->player_i->get_move(board, player);
  Move_s result = (Move_s){
      .initial = move->initial,
      .transform = move->transform,
      .captured = move->captured,
  };

  return result;
}
