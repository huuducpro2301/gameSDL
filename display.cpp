#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include <SDL_ttf.h>
#include "display.h"
int rtmenu=0;
SDL_Texture *hand_texture=NULL,*turnleft_texture=NULL,*turnright_texture=NULL,*blank_texture=NULL,*menu_tile_texture=NULL,*zz_texture=NULL;
SDL_Texture *stone_texture[102]={},*bigstone_texture=NULL,*map_texture=NULL,*hand2_texture=NULL,*flag_texture=NULL,*number[102]={};
SDL_Texture *exit1_texture=NULL,*exit2_texture=NULL,*select_texture=NULL,*pick_tile_texture=NULL,*name_texture[2]={};
SDL_Texture *bot_avatar_texture=NULL,*avatar_texture=NULL;
TTF_Font *font=NULL;
SDL_Renderer* renderer=NULL;
Mix_Chunk *type_sound=NULL,*handle_sound=NULL,*points_sound=NULL;
Mix_Music *theme_music=NULL;
SDL_Texture *get_image_texture(string path)
{
    SDL_Surface *surface = SDL_LoadBMP(path.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface( renderer, surface);
    return texture;
}
SDL_Texture *get_text_texture(string path,int font_size)
{
    TTF_Font *font = TTF_OpenFont("font.ttf",font_size);
    SDL_Color color = {0, 125, 125, 0};
    SDL_Surface* message=TTF_RenderText_Solid(font, path.c_str(), color);
   // message->w=w;message->h=h;
    SDL_Texture* texture=SDL_CreateTextureFromSurface( renderer, message);
    SDL_FreeSurface(message);
    return texture;
}
void render_image(SDL_Texture *texture,SDL_Rect rect)
{
    SDL_RenderCopy( renderer, texture, NULL, &rect );
}
void render_number(int num,SDL_Rect rect,int font_size)
{
    TTF_SizeText(font,to_string(num).c_str(),&rect.w,&rect.h);
    SDL_RenderCopy(renderer,number[num],NULL,&rect);
}
void render_text(string path,SDL_Rect rect,int font_size)
{
    TTF_Font *font = TTF_OpenFont("font.ttf",font_size);
    TTF_SizeText(font,path.c_str(),&rect.w,&rect.h);
    SDL_Color color = {0, 125, 125, 0};
    SDL_Surface* message=TTF_RenderText_Solid(font, path.c_str(), color);
    //message->w=rect.w;message->h=rect.h;
    SDL_Texture* texture=SDL_CreateTextureFromSurface( renderer, message);
    SDL_RenderCopy( renderer, texture, NULL, &rect );
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(message);
}
int check_click(SDL_Rect rect,int x,int y)
{
    return (x>=rect.x&&y>=rect.y&&x<rect.x+rect.w&&y<rect.y+rect.h);
}
void load_sound()
{
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    type_sound = Mix_LoadWAV( "sound/type.wav" );
    handle_sound=Mix_LoadWAV("sound/handle.wav");
    points_sound=Mix_LoadWAV("sound/points.wav");
    theme_music=Mix_LoadMUS("sound/theme.mp3");
}

