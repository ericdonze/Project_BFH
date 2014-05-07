#ifndef Button_H
#define Button_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

class Button
{
        public:
        Button();
        Button(int Taster, int xposition, int yposition,SDL_Renderer* Renderer);
        virtual ~Button();
    public:

        SDL_Texture* getBild();
        void setBild(SDL_Texture* truc);

        SDL_Rect getsrc_test();
        void setsrc_test(SDL_Rect truc);

        SDL_Rect getdest_test();
        void setdest_test(SDL_Rect truc);

        void set_position(int X_Achse,int Y_Achse);
        void render(SDL_Renderer* Renderer,char Taster);
        int get_hoehe(void);
        int get_breite(void);
        int get_x_position(void);
        int get_y_position(void);
        char inside_button(int mouse_x, int mouse_y);

        private:

        SDL_Texture* Taste_ungedrueckt = NULL;
        SDL_Texture* Taste_gedrueckt = NULL;
        SDL_Surface* Loading_Surf = NULL;
        SDL_Rect dest_test;
        SDL_Rect src_test;

};








#endif
