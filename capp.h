#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>
#include "entity.h"
#include "button.h"
#include <vector>
#include <stdio.h>

#define Hauptmenu 0
#define Spielablauf 1
#define Spielendcard 2




class Capp
{
    public:

        Capp();             //ctr
        virtual ~Capp();    //dtr

        int OnExecute();

    public:


        bool OnInit();                          //game init
        void OnEvent(SDL_Event* Event);         //manage all the events
        void OnLoop();                          //manage all the calculation
        void OnRender_1();
        void OnRender_2();
        void OnRender_3();
        void OnCreate();
        void OnCleanup();                       //clean all SDL tool before ending
        void OnRestart();
        void Test_Box(SDL_Renderer* box);
        SDL_Renderer* get_Renderer();

    private:

        bool Running;



        unsigned int i;

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
        SDL_Texture* text_1=NULL;
        SDL_Texture* text_2=NULL;
        SDL_Color textColor;
        SDL_Color textColor_2;
        SDL_Rect textRect;
        SDL_Rect textRect_2;
        TTF_Font *font_1;
        TTF_Font *font_2;

        SDL_Surface *message_1;
        SDL_Surface *message_2;
        SDL_Texture* Avion = NULL;
        SDL_Rect* dest = NULL;
        SDL_Rect* src = NULL;

        std::vector<Entity*> Stock;             //vector who contain all Entity
        std::vector<Button*> button;            //vector who contain all Button
        std::string data_1;
        std::string data_2;
        std::string data_3;
        std::string data_final;
        static const int WindowWidth = 1900;
        static const int WindowHeight = 1035;

        unsigned int frameLimit = SDL_GetTicks() + 16;
        int Menu=0;
        int mouse_x;
        int mouse_y;
        int vector_x;
        int vector_y;
        int winkel=4;
        unsigned int z,data_old=0;
        int w=0,h=0;
        unsigned char Taster_0=0;
        unsigned char Taster_1=0;
        unsigned char Taster_2=0;
        unsigned char Taster_3=0;
        int score;


};

#endif // CAPP_H
