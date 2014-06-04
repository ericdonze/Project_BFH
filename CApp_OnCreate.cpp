#include "Capp.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

#include "time.h"
#include <stdlib.h>

void Capp::OnCreate(){

    int alea;
    int xpos, ypos, cap;
    EEntity choix_1;
    IEntity choix_2;


    srand (time(NULL)); // init the random

    alea = rand() % 4;

    switch(alea)
    {
        case 0:
                xpos = -10;
                ypos = 300;
                cap = 0;
            break;

        case 1:
                xpos = 700;
                ypos = 1045;
                cap = 270;
            break;

        case 2:
                xpos = 1910;
                ypos = 300;
                cap = 180;
            break;

        case 3:
                xpos = 700;
                ypos = -10;
                cap = 90;
            break;

    }

    srand (time(NULL)); // init the random

    alea = rand() % 3;   // v3 in the range 1985-2014

    switch(alea)
    {
        case 0:
                choix_1 = Small;
            break;

        case 1:
                choix_1 = Big;
            break;

        case 2:
                choix_1 = Heli;
            break;
    }

    srand (time(NULL)); // init the random

    alea = rand() % 5;   // v3 in the range 1985-2014

    switch(alea)
    {
        case 0:
                choix_2 = Up;
            break;

        case 1:
                choix_2 = Down;
            break;

        case 2:
                choix_2 = Left;
            break;

        case 3:
                choix_2 = Right;
            break;

        case 4:
                choix_2 = Landing;
            break;
    }

    Stock.push_back(new Entity(choix_1,choix_2,xpos,ypos,cap,Renderer));





}
