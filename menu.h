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
    void render_menu_tile()
    {
        if (select==1)
            render_image(select_texture,rect);
        else render_image(blank_texture,rect);
        render_image(menu_tile_texture,rect);
        SDL_Rect trect=rect;
        trect.x+=20;trect.y+=20;
        render_text(name,trect,20);
    }
};
int dem=0;
void load_menu(vector <menu_tile> P)
{
    render_image(blank_texture,{0,0,2000,2000});
    SDL_Rect rect={400,0,600,600};
    render_image(zz_texture,rect);
    rect={130,100,300,300};
    render_text("MENU",rect,40);
    for (int i=0;i<P.size();i++)
    {
        P[i].render_menu_tile();
    }
    SDL_RenderPresent(renderer);
}
int select_level()
{
    SDL_Event event;
    vector <menu_tile> P;P.resize(3);
    P[0].setup(248,267,150,70,"easy",0);
    P[1].setup(248,334,150,70,"medium",0);
    P[2].setup(248,401,150,70,"hard",0);
    for (int i=0;i<3;i++)
    {
        P[i].render_menu_tile();
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
                P[i].render_menu_tile();
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
void tabmenu()
{
    Mix_PlayMusic(theme_music,-1);
    vector <menu_tile> P;P.resize(3);
    render_image(select_texture,{100,200,250,70});
    P[0].setup(100,200,150,70,"multiplayer",0);
    P[1].setup(100,267,150,70,"singleplayer",0);
    P[2].setup(100,334,150,70,"exit",0);
    load_menu(P);
    int ok=0;
    SDL_Event event;
    while (1)
    {
       //
        if (ok==1)
        {
            Mix_PlayMusic(theme_music,-1);
            ok=0;
        }
        while (SDL_PollEvent(&event))
        {
            // nhan biet chuot dang o thanh nao ma con doi mau
            if (event.type==SDL_MOUSEMOTION)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                for (int i=0;i<3;i++)
                    if (check_click(P[i].rect,x,y))
                        P[i].select=1;
                    else P[i].select=0;
                load_menu(P);
            }
            //load_menu(renderer,P);
            if (event.type==SDL_MOUSEBUTTONDOWN)
            {

                int x,y;
                SDL_GetMouseState(&x,&y);
                if (check_click(P[0].rect,x,y))
                {
                    Mix_HaltMusic();
                    multiplayer();
                    ok=1;
                    break;
                   // Mix_ResumeMusic();
                    //load_menu(renderer,P);
                    //return;
                }
                if (check_click(P[1].rect,x,y))
                {

                    int level=select_level();
                    if (level==3) {load_menu(P);continue;}
                    Mix_HaltMusic();
                    singleplayer(level);
                    ok=1;
                    break;
                   // Mix_ResumeMusic();
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
