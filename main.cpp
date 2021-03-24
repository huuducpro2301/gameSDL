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
SDL_Renderer* gRenderer = NULL;
board A;


void build_all_texture(SDL_Renderer *renderer)
{
    blank_texture = get_image_texture(renderer,"image/blank.bmp");
    map_texture=get_image_texture(renderer,"image/mapp.bmp");
    hand_texture=get_image_texture(renderer,"image/hand.bmp");
    hand2_texture=get_image_texture(renderer,"image/hand2.bmp");
    turnleft_texture=get_image_texture(renderer,"image/turnleft3.bmp");
    turnright_texture=get_image_texture(renderer,"image/turnright2.bmp");
    bigstone_texture=get_image_texture(renderer,"image/bigstone.bmp");
    menu_tile_texture=get_image_texture(renderer,"image/menutile.bmp");
    zz_texture=get_image_texture(renderer,"image/zz.bmp");
    exit1_texture=get_image_texture(renderer,"image/exitmenu1.bmp");
    exit2_texture=get_image_texture(renderer,"image/exitmenu2.bmp");
    flag_texture=get_image_texture(renderer,"image/flag.bmp");
    select_texture=get_image_texture(renderer,"image/select.bmp");
    pick_tile_texture=get_image_texture(renderer,"image/pick_tile.bmp");
    avatar_texture=get_image_texture(renderer,"image/avatar.bmp");
    bot_avatar_texture=get_image_texture(renderer,"image/bot_avatar.bmp");
    for (int i=0;i<=100;i++)
    {
        int k=i;if (k>12) k=12;
        string s="image/";s+=to_string(k);s+=".bmp";
        stone_texture[i]=get_image_texture(renderer,s);
    }
    for (int i=0;i<=100;i++)
    {
        number[i]=get_text_texture(renderer,to_string(i),15);
    }
    font = TTF_OpenFont("font.ttf",15);
}
void init()
{
    TTF_Init();
    gWindow = SDL_CreateWindow( "OH UNQUAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
      //  gScreenSurface = SDL_GetWindowSurface( gWindow );
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

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
    build_all_texture(gRenderer);
    //cerr<<*gggg<<endl;
    tabmenu(gRenderer);
	close();

	return 0;
}
