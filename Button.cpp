#include "button.h"
#include <string.h>
#include <stdio.h>

Button::Button()
{
    //ctor


    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 400;
    src_test.h = 400;

    dest_test.x = 100;
    dest_test.y = 100;
    dest_test.w = 100;
    dest_test.h = 100;
}

Button::Button(int xposition, int yposition)
{
    //ctor


    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 400;
    src_test.h = 400;

    dest_test.x = xposition;
    dest_test.y = yposition;
    dest_test.w = 100;
    dest_test.h = 100;
}

Button::~Button()
{
    //dtor
}



SDL_Texture* Button::getBild()
{
    return Bild;
}

void Button::setBild(SDL_Texture* truc)
{

    Bild = truc;
}

SDL_Rect Button::getsrc_test()
{
    return src_test;
}

void Button::setsrc_test(SDL_Rect truc)
{

    src_test = truc;
}

SDL_Rect Button::getdest_test()
{
    return dest_test;
}

void Button::setdest_test(SDL_Rect truc)
{
    dest_test = truc;
}

void Button::position(int X_Achse,int Y_Achse)
{
   dest_test.x=X_Achse;
   dest_test.y=Y_Achse;
}

void Button::render(SDL_Renderer* Renderer)
{
    SDL_RenderCopy(Renderer, Bild, &src_test, &dest_test);  //
}

void Button::loadbild(SDL_Renderer* Renderer, const char *image)
{
    SDL_Surface* Loading_Surf = NULL;

    Loading_Surf = SDL_LoadBMP(image);

    Bild = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);

    SDL_QueryTexture(Bild, NULL, NULL, &dest_test.w, &dest_test.h);

    SDL_FreeSurface(Loading_Surf);
}
