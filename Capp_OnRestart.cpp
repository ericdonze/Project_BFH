#include "Capp.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

void Capp::OnRestart()
{
    for(i=0;i<2;i++)
    {
        delete Stock[i];
    }
    Stock.clear();

    Stock.push_back(new Entity(Big,100,100,Renderer));
    Stock.push_back(new Entity(Heli,200,200,Renderer));

}

