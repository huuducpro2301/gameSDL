#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "board.h"
#include "display.h"
#include "bot.h"
void multiplayer(SDL_Renderer *renderer)
{
    rtmenu=0;
    board A;
    A.setup_num();
	A.setup_link();
	A.setup_rect();
	setup_renderer(renderer);
	A.name[1]="player 1";A.name[0]="player 2";
    name_texture[1]=get_image_texture(renderer,"image/player1_name.bmp");name_texture[0]=get_image_texture(renderer,"image/player2_name.bmp");
    A.flag=1;
    A.render_board(renderer);
    int side=3;
    while (A.cell[0].num>0||A.cell[11].num>0)
    {
        A.flag=side%2;
        A.render_board(renderer);
        player_turn(renderer,A,side);
        if (rtmenu==1) return;
        side=(side+1)%2;
    }

    A.endgame(renderer);
}
void singleplayer(SDL_Renderer *renderer,int level)
{
    rtmenu=0;
    board A;
    A.setup_num();
	A.setup_link();
	A.setup_rect();
	setup_renderer(renderer);
	A.name[1]="player 1";
	name_texture[1]=get_image_texture(renderer,"image/player_name.bmp");
	if (level==0) {name_texture[0]=get_image_texture(renderer,"image/easy_bot_name.bmp");A.name[0]="easy bot";}
	if (level==1){name_texture[0]=get_image_texture(renderer,"image/medium_bot_name.bmp");A.name[0]="medium bot";}
	if (level==2) {name_texture[0]=get_image_texture(renderer,"image/hard_bot_name.bmp");A.name[0]="hard bot";}
	A.flag=1;
	A.render_board(renderer);
	int player_side=1;int side=3;

    while (A.cell[0].num>0||A.cell[11].num>0)
    {
        A.flag=side%2;
        A.render_board(renderer);
        if (side%2==player_side) player_turn(renderer,A,side);
        else bot_turn(renderer,A,side,level);
        if (rtmenu==1) return;
        side=(side+1)%2;
    }

    A.endgame(renderer);
}
#endif
