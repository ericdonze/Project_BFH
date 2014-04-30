#include "Capp.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

bool Capp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {         //initialisation SDL
        return false;
    }

     if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) { //
        return false;
    }

    if((Window = SDL_CreateWindow("My SDL Game",    //creation main-window
     5, 40,
     WindowWidth, WindowHeight, SDL_WINDOW_MAXIMIZED)) == NULL) {
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }




    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED); //creation renderer

    Stock.push_back(new Entity(Heli,100,100,Renderer));
    Stock.push_back(new Entity(Small,200,200,Renderer));
    button.push_back(new Button(0,500,500,Renderer));
    button.push_back(new Button(0,100,100,Renderer));

	Loading_Surf = IMG_Load("Homescreen.bmp");
	if( Loading_Surf == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Spielfeld.png", IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        Background_2 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);
		if( Background_2 == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Spielfeld.png", SDL_GetError() );
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




    //const char *super1 = "hughes_20-20.png";
    //const char *super2 = "Pitts_23-23.png";


    //Stock[0]->loadbild(Renderer, super1);
    //Stock[1]->loadbild(Renderer, super2);
    Stock[0]->render(Renderer);
    Stock[1]->render(Renderer);
    button[0]->render(Renderer,0);
    button[1]->render(Renderer,0);
    SDL_RenderPresent(Renderer);





    return true;
}
