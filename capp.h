#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>

#include "entity.h"
#include "button.h"
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
        void OnRender_1();
        void OnRender_2();
        void OnCleanup();
        SDL_Renderer* get_Renderer();

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
        SDL_Texture* Background_1 = NULL;
        SDL_Texture* Background_2 = NULL;
        SDL_Texture* Avion = NULL;
        SDL_Rect* dest = NULL;
        SDL_Rect* src = NULL;
        std::vector<Entity*> Stock;
        std::vector<Button*> button;
        static const int WindowWidth = 2000;
        static const int WindowHeight = 900;
        unsigned int frameLimit = SDL_GetTicks() + 16;
        int mouse_x;
        int mouse_y;
        unsigned char Menu=0;
        #define Hauptmenu 0
        #define Spielablauf 1
        #define Spielendcard 2

};

#endif // CAPP_H
