#ifndef _BOARD_H
#define _BOARD_H
#include <SDL.h>
#include <bits/stdc++.h>
#include <SDL_mixer.h>
using namespace std;

#include "tile.h"
#include "display.h"
#include <SDL.h>
void wait(int t);
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
    void render_score();
    void render_board();
    void move_next(int start,int side);
    void move_back(int start,int side);
    void reset_none_side(int side);
    void endgame();
    void move_image(SDL_Texture *texture,SDL_Rect org,SDL_Rect deter,int time);
};

#endif // _BOARD_H
