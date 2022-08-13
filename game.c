#include <stdio.h>
#include <raylib.h>

typedef struct Pallette_s {
  Color black;
  Color white;
  Color ui_fg;
  Color ui_bg;
} Pallette_s;

typedef struct Game_s {
  Pallette_s colors;
  Board_s data;
  Player *player_b;
  Player *player_w;
  Player *cur_p;
} Game_s;

typedef struct Board_s{
  char *data;
  const int size = 8 * 8 * 2;
} Board_s;

typedef struct Piece_s{
  Image *img_b;
  Image *img_w;
  char role;
  char team;
} Piece_s;

typedef struct Grid_s {
  float cell_size;
  float offset;
} Grid_s;
typedef struct Move_s {
  Vector2 initial;
  Vector2 transform;
  Piece_s captured; // optional
} Move_s;

typedef struct Player_i {
  Move_s (*get_move)(Board_s *board, struct Player_i *player);
} Player_i;

int main(){
	printf("Hello world!\n");
  Game_s game = (Game_s){
    .colors = (Pallette_s){
      .black = BLACK,
      .white = RAYWHITE,
      .ui_fg = VIOLET,
      .ui_bg = GRAY
    }
  };

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Core example - basic window");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground(game.colors.ui_bg);
    DrawText("Hello World!",190, 200, 20, game.colors.ui_fg);

    EndDrawing();
  }
}
