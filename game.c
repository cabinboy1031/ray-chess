#include <stdio.h>
#include <raylib.h>
#include "src/board.h"
#include "src/player.h"
#include "src/grid.h"

typedef struct Pallette_s {
  Color black;
  Color white;
  Color ui_fg;
  Color ui_bg;
  Color black_piece;
  Color white_piece;
} Pallette_s;

typedef struct Game_s {
  Board_s data;
  Grid_s grid;
  Player_s *player_b;
  Player_s *player_w;
  Player_s *cur_p;
  Pallette_s colors;
} Game_s;

Game_s game_init(Player_s *player_white, Player_s *player_black);
void game_restart(Game_s*);
void game_load(Game_s*, char* filename);
void game_end(Game_s*);

Game_s game_init(Player_s *player_white, Player_s *player_black){
  return (Game_s){.data = {0},
                         .grid = (Grid_s){.cell_size = 50,
                                          .offset = (Vector2){200, 200},
                                          .bounds = (Vector2){8, 8}},
                         .player_b = player_black,
                         .player_w = player_white,
                         .cur_p = 0,
                         .colors = (Pallette_s){.black = BLACK,
                                                .white = MAROON,
                                                .ui_fg = VIOLET,
                                                .ui_bg = LIGHTGRAY,
                                                .black_piece = BLACK,
                                                .white_piece = WHITE}};
}

int main(){
	printf("Hello world!\n");
  Game_s game = game_init(0, 0);

  const int screenWidth = 800;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "Core example - basic window");
  SetTargetFPS(60);

  Color board[] = {
    game.colors.white,
    game.colors.black
  };

  struct Piece {
    Vector2 coord;
  };

  struct Piece piece = {(Vector2){0, 0}};

  while(!WindowShouldClose()){
    bool leftMouseClick = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    bool rightMouseClick = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
    Vector2 mouseCoord = GetMousePosition();

    Grid_s grid = game.grid;
    if(leftMouseClick){
      piece.coord = to_grid(grid, mouseCoord);
    }

    BeginDrawing();
        ClearBackground(game.colors.ui_bg);
        for (int i = 0; i < 64; i++) {
          int b = 0;
          if ((i / 8) % 2 != 0) {
            b = 1;
          }
          Vector2 drawCoord = to_screen(grid,
                                        (Vector2){i%8, i/8});
          DrawRectangle(drawCoord.x,
                        drawCoord.y,
                        grid.cell_size,
                        grid.cell_size,
                        board[(i + b) % 2]);
        }

        Vector2 drawCoord = to_screen(grid, piece.coord);
        DrawCircle(drawCoord.x + grid.cell_size/2,
                  drawCoord.y + grid.cell_size / 2,
                  grid.cell_size / 2,
                  game.colors.white_piece);
        DrawText("Hello World!",
                 screenWidth / 2,
                 150, 20,
                 game.colors.ui_fg);
    EndDrawing();
  }
}
