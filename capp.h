#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string.h>
#include "entity.h"
#include "button.h"
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>

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
        void OnAnimation(int x_dest,int y_dest);
        void OnRender_1();
        void OnRender_2();
        void OnRender_3();
        void OnPilotFunk();                     //Pilot Funkspeak
        void OnCreate();                        //aircraft generator
        void OnCleanup();                       //clean all SDL tool before ending
        void OnRestart();                       //prepare the program to play again
        void get_window_size(int *w,int *h);
        SDL_Renderer* get_Renderer();
        int WindowWidth;
        int WindowHeight;

    private:

        bool Running;
        bool cnt_point = 0;
        unsigned int i;

        int x_Pos;
        int y_Pos;
        int Cap_next1;
        int Cap_next2;
        int Cap_now;
        Entity Airbus;

        SDL_Window* Window;                 //Pointer on the main window
        SDL_Renderer* Renderer = NULL;      //Pointer on the  main Renderer
        SDL_Surface* Sprite = NULL;         //Pointer on the Surface for the animation
        SDL_Texture* Sprite_Anim = NULL;    //Pointer on the Texture for the animation
        SDL_Surface* Loading_Surf = NULL;   //Pointer on the Surface to load all the image
        SDL_Texture* Background_1 = NULL;   //Pointer on the Texture for the Background
        SDL_Texture* Background_2 = NULL;   //Pointer on the Texture for the Background
        SDL_Texture* Background_3 = NULL;   //Pointer on the Texture for the Background
        SDL_Texture* text_1=NULL;           //Pointer on the Texture
        SDL_Texture* text_2=NULL;           //Pointer on the Texture
        SDL_Texture* text_3=NULL;           //Pointer on the Texture
        SDL_Color textColor;                //Variable for a SDL_color
        SDL_Color textColor_2;              //Variable for a SDL_color
        SDL_Color textColor_3;              //Variable for a SDL_color
        SDL_Rect textRect;                  //position and size variable for the text
        SDL_Rect textRect_2;                //position and size variable for the text
        SDL_Rect textRect_3;                //position and size variable for the text
        TTF_Font *font_1;                   //pointer for the TTF Font
        TTF_Font *font_2;                   //pointer for the TTF Font
        TTF_Font *font_3;                   //pointer for the TTF Font
        Mix_Chunk *gcrash;                  //Sound for the crash
        Mix_Chunk *gintro;                  //Sound for the into
        Mix_Chunk *gpilot_funk_1;           //Sound for the selected aircraft
        Mix_Chunk *gpilot_funk_2;           //Sound for the selected aircraft
        Mix_Chunk *gpilot_funk_3;           //Sound for the selected aircraft
        Mix_Chunk *gpilot_funk_4;           //Sound for the selected aircraft
        Mix_Chunk *gpilot_funk_5;           //Sound for the selected aircraft
        SDL_Surface *message_1;             //Pointer on the Renderer
        SDL_Surface *message_2;             //Pointer on the Renderer
        SDL_Surface *message_3;             //Pointer on the Renderer
        SDL_Texture* Avion = NULL;          //Pointer on the Texture
        SDL_Rect* dest = NULL;
        SDL_Rect* src = NULL;



        std::vector<Entity*> Stock;             //vector who contain all Entity
        std::vector<Button*> button;            //vector who contain all Button
        std::string data_1;                     //string for the score text
        std::string data_2;                     //string for the score text
        std::string data_3;                     //string for the score text
        std::string data_final;                 //string for the score text
        std::string data_4;                     //string for the high score text
        std::string data_5;                     //string for the high score text
        std::string data_final_2;               //string for the high score text
        std::stringstream ss;                   //string stream for the score text
        std::stringstream ss_2;                 //string stream for the high score text



        unsigned int frameLimit = SDL_GetTicks() + 16;
        int Menu=0;
        int mouse_x;                    //x position from mouse
        int mouse_y;                    //y position from mouse
        int vector_x;                   //x variable for the angle vector
        int vector_y;                   //y variable for the angle vector
        int winkel=4;                   //beginning angle
        unsigned int z,data_old=0,query;
        int w=0,h=0;
        unsigned char Taster_0=0;       //beginning value 0 = not pushed
        unsigned char Taster_1=0;       //beginning value 0 = not pushed
        unsigned char Taster_2=0;       //beginning value 0 = not pushed
        unsigned char Taster_3=0;       //beginning value 0 = not pushed
        int score;                      //variable for the score
        int highscore = 0;              //variable for the high score
        ofstream monFlux_O;             //Output file stream
        ifstream monFlux_I;             //Input file stream
        Uint32 startTime = 0;
        Uint32 waitTime = 0;
        Uint32 tick = 10000;            //Beginning value for one Tick

        int WALKING_ANIMATION_FRAMES = 12;  // number of image for the explosion
        SDL_Rect SpriteRect[12];            // position and size of each bomb image
        SDL_Rect Anim_dest;                 // destination position of the animation


};

#endif // CAPP_H
