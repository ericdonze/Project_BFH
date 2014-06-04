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


    Stock.push_back(new Entity(Big,Landing,0,WindowHeight/7.5,0,Renderer));
    Stock.push_back(new Entity(Heli,Landing,WindowWidth,WindowHeight/7.5,180,Renderer));
    Stock.push_back(new Entity(Small,Landing,WindowWidth,WindowHeight/1.5,180,Renderer));



}

