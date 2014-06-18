#include "Capp.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

void Capp::OnRestart()
{
    for(i=0;i<Stock.size();i++)
    {
        delete Stock[i];
    }
    Stock.clear();
    OnCreate();
    score = 0;
    ss.str("");
    ss_2.str("");
    tick=10000;
    cnt_point = 0;
}

