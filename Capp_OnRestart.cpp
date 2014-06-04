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


    Stock.push_back(new Entity(Big,Landing,100,100,0,Renderer));
    Stock.push_back(new Entity(Heli,Landing,1500,100,180,Renderer));
    Stock.push_back(new Entity(Small,Landing,1500,400,180,Renderer));



}

