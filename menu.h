#ifndef _MENU_H
#define _MENU_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "gameplay.h"
#include "display.h"
struct menu_tile
{
    SDL_Rect rect;
    string name;
    int select;
    void setup(int x,int y,int w,int h,string s,int sl)
    {
        rect={x,y,w,h};
        name=s;
        select=sl;
    }
    void render_menu_tile(SDL_Renderer *renderer)
    {
        if (select==1)
            render_image(renderer,select_texture,rect);
        else render_image(renderer,blank_texture,rect);
        render_image(renderer,menu_tile_texture,rect);
        SDL_Rect trect=rect;
        trect.x+=20;trect.y+=20;
        render_text(renderer,name,trect,20);
    }
};
int dem=0;
void load_menu(SDL_Renderer *renderer,vector <menu_tile> P)
{
    setup_renderer(renderer);
    SDL_Rect rect={400,0,600,600};
    render_image(renderer,zz_texture,rect);
    rect={130,100,300,300};
    render_text(renderer,"MENU",rect,40);
    for (int i=0;i<P.size();i++)
    {
        P[i].render_menu_tile(renderer);
    }
    SDL_RenderPresent(renderer);
}
int select_level(SDL_Renderer *renderer)
{
    SDL_Event event;
    vector <menu_tile> P;P.resize(3);
    P[0].setup(248,267,150,70,"easy",0);
    P[1].setup(248,334,150,70,"medium",0);
    P[2].setup(248,401,150,70,"hard",0);
    for (int i=0;i<3;i++)
    {
        P[i].render_menu_tile(renderer);
    }
    SDL_RenderPresent(renderer);
   // SDL_Delay(2000);
    while (1)
    while (SDL_PollEvent(&event))
    {
        if (event.type==SDL_MOUSEMOTION)
        {
            int x,y;
            SDL_GetMouseState(&x,&y);//cerr<<x<<' '<<y<<' '<<check_click(P[0].rect,x,y)<<endl;
            for (int i=0;i<3;i++)
                if (check_click(P[i].rect,x,y)) P[i].select=1;
                else P[i].select=0;
            for (int i=0;i<3;i++)
                P[i].render_menu_tile(renderer);
            SDL_RenderPresent(renderer);
        }
        if (event.type==SDL_MOUSEBUTTONDOWN)
        {
            int x,y;
            SDL_GetMouseState(&x,&y);
            for (int i=0;i<3;i++)
                if (check_click(P[i].rect,x,y))
                {
                    return i;
                }
            return 3;
        }
    }
}
void tabmenu(SDL_Renderer *renderer)
{
    vector <menu_tile> P;P.resize(3);
    render_image(renderer,select_texture,{100,200,250,70});
    P[0].setup(100,200,150,70,"multiplayer",0);
    P[1].setup(100,267,150,70,"singleplayer",0);
    P[2].setup(100,334,150,70,"exit",0);
    load_menu(renderer,P);
    SDL_Event event;
    while (1)
    {
       //

        while (SDL_PollEvent(&event))
        {
            if (event.type==SDL_MOUSEMOTION)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                for (int i=0;i<3;i++)
                    if (check_click(P[i].rect,x,y))
                        P[i].select=1;
                    else P[i].select=0;
                load_menu(renderer,P);
            }
            //load_menu(renderer,P);
            if (event.type==SDL_MOUSEBUTTONDOWN)
            {

                int x,y;
                SDL_GetMouseState(&x,&y);
                if (check_click(P[0].rect,x,y))
                {
                    multiplayer(renderer);
                    //load_menu(renderer,P);
                    //return;
                }
                if (check_click(P[1].rect,x,y))
                {
                    int level=select_level(renderer);
                    if (level==3) {load_menu(renderer,P);continue;}
                    singleplayer(renderer,level);
                    //load_menu(renderer,P);
                }
                if (check_click(P[2].rect,x,y))
                {
                    return;
                }
            }
        }
    }
}
#endif
