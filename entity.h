#ifndef ENTITY_H
#define ENTITY_H


#include <SDL.h>
#include <SDL_image.h>


#include <iostream>
#include <string>
using namespace std;




     typedef enum
     {
          Small = 0,
          Big = 1 ,
          Heli = 2
     }EEntity;

class Entity
{
    public:
        Entity();
        Entity(EEntity aircraft,int xposition, int yposition, SDL_Renderer* moi);
        virtual ~Entity();
    public:

        SDL_Texture* getBild();
        void setBild(SDL_Texture* truc);

        SDL_Rect getsrc_test();
        void setsrc_test(SDL_Rect truc);

        SDL_Rect getdest_test();
        void setdest_test(SDL_Rect truc);
        void fly(int cap);
        bool crash(SDL_Rect a, SDL_Rect b);
        void render(SDL_Renderer* Renderer);
        void loadbild(SDL_Renderer* Renderer, const char *image);


    private:

        SDL_Texture* Bild = NULL;
        SDL_Surface* Loading_Surf_Entity = NULL;
        SDL_Rect dest_test;
        SDL_Rect src_test;

        int new_Posx;
        int new_Posy;
        int new_Cap;
        double angle;
};

#endif // ENTITY_H
