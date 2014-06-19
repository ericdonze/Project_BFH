#include "Capp.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

#include "time.h"
#include <stdlib.h>

void Capp::OnPilotFunk() // Random playback of 5 different radio message
{
    char music;
    srand (time(NULL));
    music = rand() % 5;
    switch(music)
    {
        case 0:
            Mix_PlayChannel( -1, gpilot_funk_1, 0 );
        break;

        case 1:
            Mix_PlayChannel( -1, gpilot_funk_2, 0 );
        break;

        case 2:
            Mix_PlayChannel( -1, gpilot_funk_3, 0 );
        break;

        case 3:
            Mix_PlayChannel( -1, gpilot_funk_4, 0 );
        break;

        case 4:
            Mix_PlayChannel( -1, gpilot_funk_5, 0 );
        break;
    }
}
