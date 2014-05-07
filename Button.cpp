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
    src_test.h = 130;

    dest_test.x = 100;
    dest_test.y = 100;
    dest_test.w = 400;
    dest_test.h = 130;
}

Button::Button(int Taster, int xposition, int yposition,SDL_Renderer* Renderer)
{
    //ctor

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 400;
    src_test.h = 130;

    dest_test.x = xposition;
    dest_test.y = yposition;
    dest_test.w = 400;
    dest_test.h = 130;
    switch (Taster)
    {
        case 0:

            Loading_Surf = IMG_Load("button_ungedrueckt_1.png");//IMG_Load("button_gedr�ckt.png")
            Taste_ungedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_ungedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);


            Loading_Surf = IMG_Load("button_gedrueckt_1.png");
            Taste_gedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_gedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);
        break;
        case 1:
            Loading_Surf = IMG_Load("button_ungedrueckt_2.png");//IMG_Load("button_gedr�ckt.png")
            Taste_ungedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_ungedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);


            Loading_Surf = IMG_Load("button_gedrueckt_2.png");
            Taste_gedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_gedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);
        break;
        case 2:
            Loading_Surf = IMG_Load("button_ungedrueckt_3.png");//IMG_Load("button_gedr�ckt.png")
            Taste_ungedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_ungedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);


            Loading_Surf = IMG_Load("button_gedrueckt_3.png");
            Taste_gedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_gedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);
        break;
        case 3:
            Loading_Surf = IMG_Load("button_ungedrueckt_4.png");//IMG_Load("button_gedr�ckt.png")
            Taste_ungedrueckt = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
            SDL_QueryTexture(Taste_ungedrueckt, NULL, NULL, &dest_test.w, &dest_test.h);
            SDL_FreeSurface(Loading_Surf);


            Loading_Surf = IMG_Load("button_gedrueckt_4.png");
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
int Button::get_hoehe(void)
{
    return dest_test.h;
}
int Button::get_breite(void)
{

    return dest_test.w;
}
int Button::get_x_position(void)
{
    return dest_test.x;
}
int Button::get_y_position(void)
{
    return dest_test.y;
}
char Button::inside_button(int mouse_x, int mouse_y)
{
    if(mouse_x>dest_test.x&&mouse_x<dest_test.x+dest_test.w&&mouse_y>dest_test.y&&mouse_y<dest_test.y+dest_test.h)
    {
        return true;
    }
    else
    {
        return false;
    }
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


