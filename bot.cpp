#include <bits/stdc++.h>
using namespace std;
#include <SDL.h>
#include "board.h"
#include "bot.h"
typedef pair <int,int> pp;

/*pp mediumbot(board &A,int side)
{
    srand(time(0));
    vector <int> P;
    for (int i=1;i<=5;i++)
        if (A.cell[side*5+i].num>0)
    {
        P.push_back(side*5+i);
    }
    return {P[rand()%P.size()],rand()%2};
}*/
