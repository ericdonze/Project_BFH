#include "button.h"
#include <string.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "math.h"
#include "capp.h"

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

Button::Button(int Taster, int xposition, int yposition,SDL_Renderer* Renderer)
{
    //ctor

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 400;
    src_test.h = 400;

    dest_test.x = xposition;
    dest_test.y = yposition;
    dest_test.w = 20;
    dest_test.h = 20;
    switch (Taster)
    {
        case 0:

            Loading_Surf = IMG_Load("button_ungedrueckt.png");//IMG_Load("button_gedr�ckt.png")
            Taste_ungedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_ungedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);


            Loading_Surf = IMG_Load("button_gedrueckt.png");
            Taste_gedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_gedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);
        break;
    }
}

Button::~Button()
{
    //dtor
}



SDL_Texture* Button::getBild()
{
    return Taste_ungedrueckt;
}

void Button::setBild(SDL_Texture* truc)
{

    Taste_ungedrueckt = truc;
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

void Button::set_position(int X_Achse,int Y_Achse)
{
   dest_test.x=X_Achse;
   dest_test.y=Y_Achse;
}
char Button::get_hoehe(void)
{
    return src_test.h;
}
char Button::get_breite(void)
{
    return src_test.w;
}
char Button::get_x_position(void)
{
    return dest_test.x;
}
char Button::get_y_position(void)
{
    return dest_test.y;
}

void Button::render(SDL_Renderer* Renderer,char Taster)
{
    if(Taster==0)
    {
        SDL_RenderCopy(Renderer, Taste_ungedrueckt, &src_test, &dest_test);  //
    }
    else
    {
        SDL_RenderCopy(Renderer, Taste_gedrueckt, &src_test, &dest_test);
    }

}


