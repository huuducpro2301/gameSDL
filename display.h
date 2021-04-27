#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
extern int rtmenu;
extern SDL_Texture *hand_texture,*turnleft_texture,*turnright_texture,*blank_texture,*menu_tile_texture,*zz_texture,*select_texture,*pick_tile_texture;
extern SDL_Texture *stone_texture[102],*bigstone_texture,*map_texture,*hand2_texture,*flag_texture,*number[102],*exit1_texture,*exit2_texture;
extern SDL_Texture *name_texture[2],*avatar_texture,*bot_avatar_texture;
extern TTF_Font *font;
extern SDL_Renderer* renderer;
extern Mix_Chunk *type_sound,*handle_sound,*points_sound;
extern Mix_Music *theme_music;
SDL_Texture *get_image_texture(string path);
SDL_Texture *get_text_texture(string path,int font_size);
void render_number(int num,SDL_Rect rect,int font_size);
void render_text(string path,SDL_Rect rect,int font_size);
void render_image(SDL_Texture *texture,SDL_Rect rect);
int check_click(SDL_Rect rect,int x,int y);
void load_sound();
#endif
