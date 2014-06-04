#include "Capp.h"
#include "entity.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>

bool Capp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {         //initialisation SDL
        return false;
    }

     if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) { //
        return false;
    }
    if((Window = SDL_CreateWindow("Flight-Simulator",    //creation main-window
     5, 40,
     WindowWidth, WindowHeight, SDL_WINDOW_MAXIMIZED)) == NULL) {
        return false;
    }
    else
    {
    SDL_GetWindowSize(Window,&WindowWidth,&WindowHeight);
    }


    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }




    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED); //creation renderer

    Stock.push_back(new Entity(Small,Landing,0,WindowHeight/7.5,0,Renderer));
    Stock.push_back(new Entity(Heli,Right,0,WindowHeight/2.5,10,Renderer));
    Stock.push_back(new Entity(Big,Left,0,WindowHeight/1.5,30,Renderer));

    button.push_back(new Button(0,WindowWidth/1.5,WindowHeight/1.5,Renderer));
    button.push_back(new Button(1,WindowWidth/7.5,WindowHeight/1.5,Renderer));
    button.push_back(new Button(2,WindowWidth/1.5,WindowHeight/1.5,Renderer));
    button.push_back(new Button(3,WindowWidth/2.5,WindowHeight/1.5,Renderer));


    Loading_Surf = IMG_Load("Spielendcard.png");
	if( Loading_Surf == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Spielendcard.png", IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        Background_3 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
		if( Background_3 == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Spielendcard.png", SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(Loading_Surf);
	}


	Loading_Surf = IMG_Load("Startbildschirm.png");
	if( Loading_Surf == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Startbildschirm.png", IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        Background_2 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
		if( Background_2 == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Startbildschirm.png", SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(Loading_Surf);
	}



    Loading_Surf = IMG_Load("Spielfeld.png");
	if( Loading_Surf == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Spielfeld.png", IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        Background_1 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
		if( Background_1 == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Spielfeld.png", SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(Loading_Surf);
    }
    if( TTF_Init() == -1 )
    {
        return false;
    }

    font_1 = TTF_OpenFont( "Tahoma.ttf", 20 );
    if( font_1 == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", "Tahoma.ttf", SDL_GetError() );
    }
    font_2 = TTF_OpenFont( "Tahoma.ttf", 50 );
    if( font_2 == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", "Tahoma.ttf", SDL_GetError() );
    }
    data_2="";

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
     gcrash = Mix_LoadWAV( "crash.wav" );
    if( gcrash == NULL )
    {
        printf( "Failed to load gcrash sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    gintro = Mix_LoadWAV( "20th Century Fox.wav" );
    if( gintro == NULL )
    {
        printf( "Failed to load gintro sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    Mix_PlayChannel( -1, gintro, 0 );








    return true;
}
