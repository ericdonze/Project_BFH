#ifndef AVION_H
#define AVION_H

#include <SDL.h>


class Avion
{
    public:
        Avion();
        virtual ~Avion();

    private:

        SDL_Texture* Avion_class = NULL;
};

#endif // AVION_H
