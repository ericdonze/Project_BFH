#ifndef CSURFACE_H
#define CSURFACE_H

#include <SDL.h>

class CSurface
{
    public:
        CSurface();
        virtual ~CSurface();

    public:

        static SDL_Surface* OnLoad(char* File);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};

#endif // CSURFACE_H
