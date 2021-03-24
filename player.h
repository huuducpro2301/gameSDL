#ifndef _PLAYER_H
#define _PLAYER_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "board.h"
#include "display.h"
#include "tile.h"
void player_turn(SDL_Renderer *renderer,board &A,int side)
{
    SDL_Event event;
    int pos_arrow=0;
    A.reset_none_side(renderer,side);
    int xside=side;side%=2;
    render_image(renderer,exit1_texture,{100,50,100,50});
    SDL_RenderPresent(renderer);
    while (1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type==SDL_MOUSEMOTION)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                if (check_click({100,50,100,50},x,y))
                {
                    render_image(renderer,exit2_texture,{100,50,100,50});
                    SDL_RenderPresent(renderer);
                }
                else
                {
                    render_image(renderer,exit1_texture,{100,50,100,50});
                    SDL_RenderPresent(renderer);
                }
            }
            if (event.type==SDL_MOUSEBUTTONDOWN)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                if (check_click({100,50,100,50},x,y))
                {
                    rtmenu=1;
                    return;
                }
                if (pos_arrow>0)
                {
                    SDL_Rect arrow=A.cell[5*side+pos_arrow].rect;
                    arrow.x-=20;arrow.y+=15;arrow.w=50;arrow.h=50;
                    if (check_click(arrow,x,y))
                    {
                        if (side==0) A.move_back(renderer,pos_arrow,xside);
                        else A.move_next(renderer,5+pos_arrow,xside);
                        return;
                    }
                    arrow.x+=80;
                    if (check_click(arrow,x,y))
                    {
                        if (side==0) A.move_next(renderer,pos_arrow,xside);
                        else A.move_back(renderer,5+pos_arrow,xside);
                        return;
                    }

                }
                for (int i=1;i<=5;i++)
                {
                    SDL_Rect rect=A.cell[5*side+i].rect;
                    if (A.cell[5*side+i].num==0)
                    {

                        continue;
                    }

                    if (check_click(rect,x,y))
                    {
                        pos_arrow=i;
                        SDL_Rect arrow=rect;arrow.x-=20;arrow.y+=25;arrow.w=50;arrow.h=50;
                        A.render_board(renderer);
                        SDL_Rect rr=rect;rr.x+=6;rr.y+=6;rr.w-=12;rr.h-=12;
                        render_image(renderer,pick_tile_texture,rr);

                        render_image(renderer,turnleft_texture,arrow);

                        arrow.x=rect.x+75;
                        render_image(renderer,turnright_texture,arrow);
                        SDL_RenderPresent(renderer);

                    }

                }
                render_image(renderer,exit1_texture,{100,50,100,50});
                SDL_RenderPresent(renderer);

            }

        }
    }
}
#endif
