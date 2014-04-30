#ifndef Button_H
#define Button_H


#include <SDL.h>


#include <iostream>
#include <string>
using namespace std;

class Button
{
        public:
        Button();
        Button(int xposition, int yposition);
        virtual ~Button();
    public:

        SDL_Texture* getBild();
        void setBild(SDL_Texture* truc);

        SDL_Rect getsrc_test();
        void setsrc_test(SDL_Rect truc);

        SDL_Rect getdest_test();
        void setdest_test(SDL_Rect truc);
        void position(int X_Achse,int Y_Achse);
        void render(SDL_Renderer* Renderer);
        void loadbild(SDL_Renderer* Renderer, const char *image);
        char laenge(void);

        private:

        SDL_Texture* Bild = NULL;
        SDL_Rect dest_test;
        SDL_Rect src_test;
};








#endif
