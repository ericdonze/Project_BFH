#include "entity.h"
#include <string.h>
#include <stdio.h>

Entity::Entity()
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    new_Cap = 4;

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = 100;
    dest_test.y = 100;
    dest_test.w = 100;
    dest_test.h = 100;
}

Entity::Entity(int xposition, int yposition)
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    new_Cap = 4;

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = xposition;
    dest_test.y = yposition;
    dest_test.w = 100;
    dest_test.h = 100;
}

Entity::~Entity()
{
    //dtor
}

SDL_Texture* Entity::getBild()
{
    return Bild;
}

void Entity::setBild(SDL_Texture* truc)
{

    Bild = truc;
}

SDL_Rect Entity::getsrc_test()
{
    return src_test;
}

void Entity::setsrc_test(SDL_Rect truc)
{

    src_test = truc;
}

SDL_Rect Entity::getdest_test()
{
    return dest_test;
}

void Entity::setdest_test(SDL_Rect truc)
{
    dest_test = truc;
}

void Entity::fly(int cap)
{




    printf("cap:%d\n",cap);

    if (cap != new_Cap)         //difference of cap
    {


        new_Cap = cap;

    switch(new_Cap)             //between 0 and 15
         {

             case 0:
                new_Posx = 0;
                new_Posy = 2;
             break;

             case 1:
                new_Posx = 1;
                new_Posy = 2;
             break;

             case 2:
                new_Posx = 2;
                new_Posy = 2;
             break;

             case 3:
                new_Posx = 2;
                new_Posy = 1;
             break;

             case 4:
                new_Posx = 2;
                new_Posy = 0;
             break;

             case 5:
                new_Posx = 2;
                new_Posy = -1;
             break;

             case 6:
                new_Posx = 2;
                new_Posy = -2;
             break;

             case 7:
                new_Posx = 1;
                new_Posy = -2;
             break;

             case 8:
                new_Posx = 0;
                new_Posy = -2;
             break;

             case 9:
                new_Posx = -1;
                new_Posy = -2;
             break;

             case 10:
                new_Posx = -2;
                new_Posy = -2;
             break;

             case 11:
                new_Posx = -2;
                new_Posy = -1;
             break;

             case 12:
                new_Posx = -2;
                new_Posy = 0;
             break;

             case 13:
                new_Posx = -2;
                new_Posy = 1;
             break;

             case 14:
                new_Posx = -2;
                new_Posy = 2;
             break;

             case 15:
                new_Posx = -1;
                new_Posy = 2;
             break;


             break;
         }

    }

        dest_test.x += new_Posx;
        dest_test.y += new_Posy;
}

void Entity::render(SDL_Renderer* Renderer)
{
    SDL_RenderCopy(Renderer, Bild, &src_test, &dest_test);  //
}

void Entity::loadbild(SDL_Renderer* Renderer, const char *image)
{
    SDL_Surface* Loading_Surf = NULL;

    Loading_Surf = SDL_LoadBMP(image);

    Bild = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);

    SDL_QueryTexture(Bild, NULL, NULL, &dest_test.w, &dest_test.h);

    SDL_FreeSurface(Loading_Surf);
}
