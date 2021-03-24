#ifndef _BOARD_H
#define _BOARD_H
#include <SDL.h>
#include <bits/stdc++.h>
using namespace std;

#include "tile.h"
#include "display.h"
#include <SDL.h>

class board
{
public:
    tile cell[12];
    int nback[12],nnext[12],score[2],sub[2];
    int flag;
    string name[2];
public:
    void setup_num();
    void setup_link();
    void setup_rect();
    void render_score(SDL_Renderer *renderer);
    void render_board(SDL_Renderer *renderer);
    void move_next(SDL_Renderer *renderer,int start,int side);
    void move_back(SDL_Renderer *renderer,int start,int side);
    void reset_none_side(SDL_Renderer *renderer,int side);
    void endgame(SDL_Renderer *renderer);
    void move_image(SDL_Renderer *renderer,SDL_Texture *texture,SDL_Rect org,SDL_Rect deter,int time);
};

#endif // _BOARD_H
