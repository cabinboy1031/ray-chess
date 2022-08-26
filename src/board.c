#include "board.h"
#include <stdlib.h>

void load_piece(piece_map_t *map, char key, char* white_sprite_dir, char* black_sprite_dir){
  Piece_s *piece = malloc(sizeof(piece));
    piece->role = key;
    piece->img_b = LoadImage(black_sprite_dir);
    piece->img_w = LoadImage(white_sprite_dir);

  const char* temp = key;
  map_set(map, temp, piece);
}

map_int_t load_pieces(){
  map_int_t pieces;
  map_init(&pieces);

  return pieces;
}

void unload_pieces(piece_map_t *map){
  const char *key; 
  map_iter_t iter = map_iter(map);
  while((key = map_next(map, &iter))){
    free(map_get(map, key));
  }
  map_deinit(map);
}