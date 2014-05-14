#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>
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
        void OnRender_3();
        void OnCleanup();
        void OnRestart();
        void Test_Box(SDL_Renderer* box);
        SDL_Renderer* get_Renderer();

    private:

        bool Running;



        char i;

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
        SDL_Texture* Background_3 = NULL;
        SDL_Texture* text=NULL;
        SDL_Color textColor;
        SDL_Rect textRect;
        TTF_Font *font;

        SDL_Surface *message;
        SDL_Texture* Avion = NULL;
        SDL_Rect* dest = NULL;
        SDL_Rect* src = NULL;

        std::vector<Entity*> Stock;
        std::vector<Button*> button;
        std::string data;
        static const int WindowWidth = 2000;
        static const int WindowHeight = 900;
        unsigned int frameLimit = SDL_GetTicks() + 16;
        int Menu=0;
        int mouse_x;
        int mouse_y;
        int vector_x;
        int vector_y;
        int winkel=4;
        int w=0,h=0;
        unsigned char Taster_0=0;
        unsigned char Taster_1=0;
        unsigned char Taster_2=0;
        unsigned char Taster_3=0;
        #define Hauptmenu 0
        #define Spielablauf 1
        #define Spielendcard 2

};

#endif // CAPP_H
