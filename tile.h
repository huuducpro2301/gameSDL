#ifndef _TILE_H
#define _TILE_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "display.h"
using namespace std;

class tile
{
public:
    SDL_Rect rect,rect_num;
    int num;
public:
    void render_tile(SDL_Renderer* renderer)
    {
        int ok=0;int n=num;
        if (n>=100)
        {
            ok=1;n-=100;
        }
        SDL_Rect rr=rect;
        rr.x+=11;rr.y+=18;rr.w=80;rr.h=80;
        render_image(renderer,stone_texture[n],rr);
        if (ok==1)
        {
            SDL_Rect gg;
            gg.x=rect.x+16;gg.y=rect.y+75;
            gg.w=60;gg.h=60;
            render_image(renderer,bigstone_texture,gg);
            gg=rect;
            gg.x+=51;gg.w=10;gg.h=10;
            TTF_SizeText(font,to_string(n+10).c_str(),&gg.w,&gg.h);
            SDL_RenderCopy(renderer,number[n+10],NULL,&gg);
            //SDL_RenderCopy(renderer,number[n+10],NULL,&gg);

        }
        else
        {
            SDL_Rect gg=rect;
            gg.x+=51;gg.w=10;gg.h=10;
            TTF_SizeText(font,to_string(n).c_str(),&gg.w,&gg.h);
            SDL_RenderCopy(renderer,number[n],NULL,&gg);
        }
    }
    //void add_surface(SDL_Surface)
};

#endif // _TILE_H
