#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "board.h"
#include "display.h"
#include "bot.h"
void multiplayer()
{
    rtmenu=0;
    board A;
    A.setup_num();
	A.setup_link();
	A.setup_rect();

	A.name[1]="player 1";A.name[0]="player 2";
    name_texture[1]=get_image_texture("image/player1_name.bmp");
    name_texture[0]=get_image_texture("image/player2_name.bmp");
    A.flag=1;
    A.render_board();
    int side=3;
    while (A.cell[0].num>0||A.cell[11].num>0)
    {
        A.flag=side%2;
        A.render_board();
        player_turn(A,side);
        if (rtmenu==1) return;
        side=(side+1)%2;
    }

    A.endgame();
}
void singleplayer(int level)
{
    rtmenu=0;
    board A;
    A.setup_num();
	A.setup_link();
	A.setup_rect();

	A.name[1]="player 1";
	name_texture[1]=get_image_texture("image/player_name.bmp");
	if (level==0) {name_texture[0]=get_image_texture("image/easy_bot_name.bmp");A.name[0]="easy bot";}
	if (level==1){name_texture[0]=get_image_texture("image/medium_bot_name.bmp");A.name[0]="medium bot";}
	if (level==2) {name_texture[0]=get_image_texture("image/hard_bot_name.bmp");A.name[0]="hard bot";}
	A.flag=1;
	A.render_board();
	int player_side=1;int side=3;

    while (A.cell[0].num>0||A.cell[11].num>0)
    {
        A.flag=side%2;
        A.render_board();
        if (side%2==player_side) player_turn(A,side);
        else bot_turn(A,side,level);
        if (rtmenu==1) return;
        side=(side+1)%2;
    }

    A.endgame();
}
#endif
