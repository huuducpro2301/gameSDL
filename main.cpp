#include <SDL.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "board.h"
#include "player.h"
#include "display.h"
#include "gameplay.h"
#include "menu.h"

using namespace std;
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;

SDL_Window* gWindow = NULL;
SDL_Window* gg=NULL;
SDL_Surface* gScreenSurface = NULL;

board A;


void build_all_texture()
{
    blank_texture = get_image_texture("image/blank.bmp");
    map_texture=get_image_texture("image/mapp.bmp");
    hand_texture=get_image_texture("image/hand.bmp");
    hand2_texture=get_image_texture("image/hand2.bmp");
    turnleft_texture=get_image_texture("image/turnleft3.bmp");
    turnright_texture=get_image_texture("image/turnright2.bmp");
    bigstone_texture=get_image_texture("image/bigstone.bmp");
    menu_tile_texture=get_image_texture("image/menutile.bmp");
    zz_texture=get_image_texture("image/zz.bmp");
    exit1_texture=get_image_texture("image/exitmenu1.bmp");
    exit2_texture=get_image_texture("image/exitmenu2.bmp");
    flag_texture=get_image_texture("image/flag.bmp");
    select_texture=get_image_texture("image/select.bmp");
    pick_tile_texture=get_image_texture("image/pick_tile.bmp");
    avatar_texture=get_image_texture("image/avatar.bmp");
    bot_avatar_texture=get_image_texture("image/bot_avatar.bmp");
    for (int i=0;i<=100;i++)
    {
        int k=i;if (k>12) k=12;
        string s="image/";s+=to_string(k);s+=".bmp";
        stone_texture[i]=get_image_texture(s);
    }
    for (int i=0;i<=100;i++)
    {
        number[i]=get_text_texture(to_string(i),15);
    }
    font = TTF_OpenFont("font.ttf",15);
}
void init()
{
    TTF_Init();
    gWindow = SDL_CreateWindow( "OH UNQUAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
      //  gScreenSurface = SDL_GetWindowSurface( gWindow );
    renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    load_sound();assert(type_sound!=NULL);


}


void close()
{
	//Deallocate surface


	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
int main( int argc, char* args[] )
{
	init();
    build_all_texture();
    //cerr<<*gggg<<endl;
    tabmenu();
	close();

	return 0;
}
