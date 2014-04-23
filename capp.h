#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include "entity.h"
#include <vector>


class Capp
{
    public:

        Capp();             //ctr
        virtual ~Capp();    //dtr

        int OnExecute();

    public:

        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();

    private:

        bool Running;
        int x_Pos;
        int y_Pos;
        int Cap_next1;
        int Cap_next2;
        int Cap_now;
        Entity Airbus;

        SDL_Window* Window; //You can draw on it
        SDL_Renderer* Renderer = NULL;
        SDL_Surface* Sprite = NULL;
        SDL_Surface* Loading_Surf = NULL;
        SDL_Texture* Background = NULL;
        SDL_Texture* Avion = NULL;
        SDL_Rect* dest = NULL;
        SDL_Rect* src = NULL;
        std::vector<Entity*> Stock;

        static const int WindowWidth = 640;
        static const int WindowHeight = 580;
        unsigned int frameLimit = SDL_GetTicks() + 16;

};

#endif // CAPP_H
