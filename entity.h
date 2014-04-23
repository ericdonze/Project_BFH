#ifndef ENTITY_H
#define ENTITY_H


#include <SDL.h>


#include <iostream>
#include <string>
using namespace std;


class Entity
{
    public:
        Entity();
        Entity(int xposition, int yposition);
        virtual ~Entity();
    public:

        SDL_Texture* getBild();
        void setBild(SDL_Texture* truc);

        SDL_Rect getsrc_test();
        void setsrc_test(SDL_Rect truc);

        SDL_Rect getdest_test();
        void setdest_test(SDL_Rect truc);

        void fly(int cap);
        void render(SDL_Renderer* Renderer);
        void loadbild(SDL_Renderer* Renderer, const char *image);


    private:

        SDL_Texture* Bild = NULL;
        SDL_Rect dest_test;
        SDL_Rect src_test;

        int new_Posx;
        int new_Posy;
        int new_Cap;
};

#endif // ENTITY_H
