#include <bits/stdc++.h>
using namespace std;
#include "board.h"
void wait(int t)
{
    int start=SDL_GetTicks();
    while (SDL_GetTicks()-start<t);
    return;
}
void board::setup_num()
{
    for (int i=1;i<=10;i++)
        cell[i].num=5;
    cell[0].num=100;
    cell[11].num=100;
    score[0]=score[1]=sub[0]=sub[1]=0;
   // cell[1].num=0;
   // cell[5].num=cell[8].num=cell[10].num=0;
   // cell[1].num=cell[2].num=cell[3].num=0;
}
void board::setup_link()
{
    for (int i=1;i<=4;i++)
    {
        nnext[i]=i+1;
        nback[i+1]=i;
    }
    for (int i=6;i<=9;i++)
    {
        nback[i]=i+1;
        nnext[i+1]=i;
    }
    nback[1]=0;nnext[0]=1;
    nnext[5]=11;nback[11]=5;
    nnext[6]=0;nback[0]=6;
    nback[10]=11;nnext[11]=10;
}
void board::setup_rect()
{
    cell[1].rect={310,215,100,109};
    cell[2].rect={413,215,100,109};
    cell[3].rect={516,215,100,109};
    cell[4].rect={619,215,100,109};
    cell[5].rect={721,215,100,109};
    cell[6].rect={310,327,100,109};
    cell[7].rect={413,327,100,109};
    cell[8].rect={516,327,100,109};
    cell[9].rect={619,327,100,109};
    cell[10].rect={721,327,100,109};
    cell[0].rect={210,245,100,109};
    cell[11].rect={818,245,100,109};
}
void board::render_score()
{
    SDL_Rect rect={706,90,80,80};
    render_text(to_string(score[0]%100+(score[0]/100)*10-sub[0]),rect,30);
    //render_number(renderer,score[0]%100+(score[0]/100)*10-sub[0],rect,30);
    rect={520,520,80,80};
    render_text(to_string(score[1]%100+(score[1]/100)*10-sub[1]),rect,30);
    //render_number(renderer,score[1]%100+(score[1]/100)*10-sub[1],rect,30);
    rect={590,63,80,80};
    int k=score[0]%100+(score[0]/100)*10-sub[0];
    render_image(stone_texture[k],rect);

    rect={410,500,80,80};
    k=score[1]%100+(score[1]/100)*10-sub[1];
    render_image(stone_texture[k],rect);

}
void board::render_board()
{
    SDL_RenderClear(renderer);
    SDL_Rect rect;
    rect={0,0,1080,640};
    render_image(map_texture,rect);
    for (int i=0;i<12;i++)
    {
        cell[i].render_tile();
    }
    render_score();
    rect={650,470,100,100};
    SDL_RenderCopy(renderer,avatar_texture,NULL,&rect);
    rect.x-=35;rect.y+=100;rect.w=180;rect.h=60;
    SDL_RenderCopy(renderer,name_texture[1],NULL,&rect);
    //render_text(renderer,name[1],{700,540,120,60},30);
    rect={380,33,100,100};
    //cerr<<name[0].length()<<' '<<name[0]<<endl;
    if (name[0].substr(name[0].length()-3,3)=="bot")
        SDL_RenderCopy(renderer,bot_avatar_texture,NULL,&rect);
    else SDL_RenderCopy(renderer,avatar_texture,NULL,&rect);
    rect.x-=35;rect.y+=100;rect.w=180;rect.h=60;
    SDL_RenderCopy(renderer,name_texture[0],NULL,&rect);
    if (flag==1)
    {
        render_image(flag_texture,{600,500,40,40});
    }
    else render_image(flag_texture,{510,73,40,40});
    SDL_RenderPresent(renderer);
}
void board::move_next(int start,int side)
{
    int cur=start;int num=cell[start].num;cell[start].num=0;
    render_board();
    render_image(hand2_texture,cell[cur].rect);
    SDL_RenderPresent(renderer);
    if (num>1) Mix_PlayChannel(-1,handle_sound,0);
    SDL_Delay(100);

    for (int i=1;i<=num;i++)
    {
        move_image(hand_texture,cell[cur].rect,cell[nnext[cur]].rect,1);
        cur=nnext[cur];
        cell[cur].num++;
        Mix_PlayChannel(-1,type_sound,0);
        SDL_Delay(100);

    }
    cur=nnext[cur];
    if (cur==0||cur==11) {render_board(); return;}
    if (cell[cur].num>0)
    {
        move_image(hand_texture,cell[nback[cur]].rect,cell[cur].rect,1);
        move_next(cur,side);
    }
    else
        while (cell[cur].num==0)
        {

            cur=nnext[cur];
            if (side>1)
                if (cur==0||cur==11) {render_board(); return;}
            score[side%2]+=cell[cur].num;
            SDL_Rect rect_score={590,55,80,80};
            if (side%2==1) rect_score={410,490,80,80};
            if (cell[cur].num>0)
            {
                cell[cur].num=0;
                Mix_PlayChannel(-1,points_sound,0);
                move_image(hand_texture,cell[cur].rect,rect_score,1);
                render_board();
                SDL_Delay(100);
                cur=nnext[cur];

            }
            else break;
        }
    render_board();
}
void board::move_back(int start,int side)
{
    int cur=start;int num=cell[start].num;cell[start].num=0;
    render_board();
    render_image(hand2_texture,cell[cur].rect);

    SDL_RenderPresent(renderer);
    if (num>1) Mix_PlayChannel(-1,handle_sound,0);
    SDL_Delay(100);

    //wait(100);
    for (int i=1;i<=num;i++)
    {
        move_image(hand_texture,cell[cur].rect,cell[nback[cur]].rect,1);
        cur=nback[cur];
        cell[cur].num++;
        SDL_Rect rect=cell[cur].rect;
        Mix_PlayChannel(-1,type_sound,0);
        SDL_Delay(100);

        //wait(100);
    }
    cur=nback[cur];
    if (cur==0||cur==11) {render_board(); return;}
    if (cell[cur].num>0)
    {
        move_image(hand_texture,cell[nnext[cur]].rect,cell[cur].rect,1);
        move_back(cur,side);
    }
    else
        while (cell[cur].num==0)
        {
            cur=nback[cur];
            if (side>1)
                if (cur==0||cur==11) {render_board(); return;}
            score[side%2]+=cell[cur].num;
            SDL_Rect rect_score={590,55,80,80};
            if (side%2==1) rect_score={410,490,80,80};
            if (cell[cur].num>0)
            {
                cell[cur].num=0;
                Mix_PlayChannel(-1,points_sound,0);
                move_image(hand_texture,cell[cur].rect,rect_score,1);
                render_board();
                SDL_Delay(100);
                cur=nback[cur];

            }
            else break;
        }
    render_board();
}
void board::reset_none_side(int side)
{
    for (int i=1;i<=5;i++)
        if (cell[side*5+i].num>0) return;
    for (int i=1;i<=5;i++)
        cell[side*5+i].num=1;
    sub[side]+=5;
    render_board();
}
void board::endgame()
{
    SDL_Delay(300);
    for (int i=1;i<=10;i++)
    {
        score[(i-1)/5]+=cell[i].num;
        cell[i].num=0;
    }
    render_board();
    int a1=score[1]%100+(score[1]/100)*10-sub[1];
    int a2=score[0]%100+(score[0]/100)*10-sub[0];
    render_image(blank_texture,{350,278,400,100});
    render_image(menu_tile_texture,{350,278,400,100});
    if (a1==a2) render_text("draw",{400,300,400,100},50);
    if (a1<a2) render_text(name[0]+" win",{400,300,400,100},40);
    if (a1>a2) render_text(name[1]+" win",{400,300,400,100},40);
    render_image(exit1_texture,{100,50,100,50});
    SDL_RenderPresent(renderer);
    SDL_Event event;
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
                    render_image(exit2_texture,{100,50,100,50});
                    SDL_RenderPresent(renderer);
                }
                else
                {
                    render_image(exit1_texture,{100,50,100,50});
                    SDL_RenderPresent(renderer);
                }
            }
            if (event.type==SDL_MOUSEBUTTONDOWN)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                if (check_click({100,50,100,50},x,y))
                    return;
            }
        }
    }
}
void board::move_image(SDL_Texture *texture,SDL_Rect org,SDL_Rect deter,int time)
{
    int num=10;
    int s=abs(org.x-deter.x)+abs(org.y-deter.y);
    num+=(s/300)*5;

    render_image(texture,org);
    SDL_RenderPresent(renderer);
    for (int i=num;i>=1;i--)
    {
        int dx=(deter.x-org.x)/i;
        int dy=(deter.y-org.y)/i;
        org.x+=dx;org.y+=dy;
        if (dx==0&&dy==0) continue;
       // setup_renderer(renderer);
        render_board();
        render_image(texture,org);
        SDL_RenderPresent(renderer);
        SDL_Delay(15);
       // wait(15);
    }
}
