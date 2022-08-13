#include <stdio.h>
#include <raylib.h>
#include "src/board.h"
#include "src/player.h"

typedef struct Pallette_s {
  Color black;
  Color white;
  Color ui_fg;
  Color ui_bg;
} Pallette_s;

typedef struct Game_s {
  Pallette_s colors;
  Board_s data;
  Player_s *player_b;
  Player_s *player_w;
  Player_s *cur_p;
} Game_s;

Game_s* game_init();
void game_restart(Game_s*);
void game_load(Game_s*, char* filename);
void game_end(Game_s*);


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
