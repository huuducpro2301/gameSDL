#ifndef _BOT_H
#define _BOT_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "board.h"
#include "display.h"
typedef pair <int,int> pp;

int move_value(board &A,int start,int dir)
{
    int cur=start;
    int res=0;
    while (1)
    {
        int num=A.cell[cur].num;A.cell[cur].num=0;
        for (int i=1;i<=num;i++)
        {
            if (dir==0) cur=A.nnext[cur];else cur=A.nback[cur];
            A.cell[cur].num++;
        }
        if (dir==0) cur=A.nnext[cur];else cur=A.nback[cur];
        if (cur==0||cur==11) {return 0;}
        if (A.cell[cur].num>0)
        {
            continue;
        }
        else
        {
            while (A.cell[cur].num==0)
            {

                if (dir==0) cur=A.nnext[cur];else cur=A.nback[cur];
                res+=A.cell[cur].num;
                //cerr<<"cc "<<A.cell[cur].num<<" ";
                if (A.cell[cur].num>0)
                {
                    A.cell[cur].num=0;
                    if (dir==0) cur=A.nnext[cur];else cur=A.nback[cur];

                }
                else return res;
            }
            break;
        }
    }
    return res;
}
pair <int,pp> getmax(board &A,int side,int depth)
{
    if (depth==0) return {0,{0,0}};
    if (A.cell[0].num==0&&A.cell[11].num==0) return {0,{0,0}};
    vector <int> P;
    for (int i=1;i<=5;i++)
        if (A.cell[side*5+i].num>0)
    {
        P.push_back(side*5+i);
    }
    int sub=0;
    if (P.size()==0)
    {
        for (int i=1;i<=5;i++)
        {
            A.cell[side*5+i].num=1;
            P.push_back(side*5+i);
        }
        sub=5;
    }
    int res=-1e9;pp turn={0,0};
    for (int i=0;i<P.size();i++)
    {
        board B=A;
        int gg=move_value(B,P[i],0);gg=gg%100+(gg/100)*10-sub;
        if (res<gg-getmax(B,1-side,depth-1).first)
        {
            res=gg-getmax(B,1-side,depth-1).first;
            turn={P[i],0};
        }
        B=A;
        gg=move_value(B,P[i],1); gg=gg%100+(gg/100)*10-sub;

        if (res<gg-getmax(B,1-side,depth-1).first)
        {
            res=gg-getmax(B,1-side,depth-1).first;
            turn={P[i],1};
        }

    }
    return {res,turn};
}
pp easybot(board &A,int side)
{
    board B=A;
    return getmax(A,side,1).second;
}
pp mediumbot(board &A,int side)
{
    board B=A;
    return getmax(A,side,4).second;
}
pp hardbot(board &A,int side)
{
    board B=A;
    return getmax(A,side,6).second;
}

void bot_turn(SDL_Renderer *renderer,board &A,int side,int level)
{
    A.reset_none_side(renderer,side);
    pp turn;
    if (level==0) turn=easybot(A,side);
   if (level==1) turn=mediumbot(A,side);
   if (level==2) turn=hardbot(A,side);
    if (side!=turn.second)
    {
        SDL_Rect rect=A.cell[5*side+turn.first].rect;

        SDL_Rect arrow=rect;arrow.x-=20;arrow.y+=25;arrow.w=50;arrow.h=50;
        A.render_board(renderer);
        SDL_Rect rr=rect;rr.x+=6;rr.y+=6;rr.w-=12;rr.h-=12;
                        render_image(renderer,pick_tile_texture,rr);
        render_image(renderer,turnleft_texture,arrow);
    }
    else
    {
        SDL_Rect rect=A.cell[5*side+turn.first].rect;

        SDL_Rect arrow=rect;arrow.x+=70;arrow.y+=25;arrow.w=50;arrow.h=50;
        A.render_board(renderer);
        SDL_Rect rr=rect;rr.x+=6;rr.y+=6;rr.w-=12;rr.h-=12;
                        render_image(renderer,pick_tile_texture,rr);
        render_image(renderer,turnright_texture,arrow);

    }
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
        //A.render_board(renderer);
    if (turn.second==0) A.move_next(renderer,turn.first,side);
    else A.move_back(renderer,turn.first,side);
}
#endif
