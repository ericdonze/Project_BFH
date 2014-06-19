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
    //create all buttons
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
    //create all font to write on the screen
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
    font_3 = TTF_OpenFont( "Tahoma.ttf", 50 );
    if( font_3 == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", "Tahoma.ttf", SDL_GetError() );
    }
    data_4="";

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
    gpilot_funk_1 = Mix_LoadWAV( "Pilot Funk1.wav" );
    gpilot_funk_2 = Mix_LoadWAV( "Pilot Funk2.wav" );
    gpilot_funk_3 = Mix_LoadWAV( "Pilot Funk3.wav" );
    gpilot_funk_4 = Mix_LoadWAV( "Pilot Funk4.wav" );
    gpilot_funk_5 = Mix_LoadWAV( "Pilot Funk5.wav" );
    if( gpilot_funk_1 == NULL &&gpilot_funk_2 == NULL &&gpilot_funk_3 == NULL &&gpilot_funk_4 == NULL &&gpilot_funk_5 == NULL)
    {
        printf( "Failed to load pilot funk sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    Loading_Surf = IMG_Load("bombe.png");
	if( Loading_Surf == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "bombe.png", IMG_GetError() );
	}
	else
	{
	    Sprite_Anim = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
		if( Sprite_Anim == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "bombe.png", SDL_GetError() );
		}
	    SDL_FreeSurface(Loading_Surf);
	}








    return true;
}
