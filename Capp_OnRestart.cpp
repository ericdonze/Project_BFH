#include "Capp.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

void Capp::OnRestart()
{
    for(i=0;i<Stock.size();i++) //delete all aircraft
    {
        delete Stock[i];
    }
    Stock.clear();              //clean the stock
    OnCreate();                 //create a new aircraft
    score = 0;                  //{
    ss.str("");                 //set the point back
    ss_2.str("");               //
    cnt_point = 0;              //}
    tick=10000;                 //set the time back to 10sec

}

