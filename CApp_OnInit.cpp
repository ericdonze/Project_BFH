#include "Capp.h"

bool Capp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {         //initialisation SDL
        return false;
    }

     if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) { //
        return false;
    }

    if((Window = SDL_CreateWindow("My SDL Game",    //creation main-window
     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
     WindowWidth, WindowHeight, 0)) == NULL) {
        return false;
    }


    Stock.push_back(new Entity());
    Stock.push_back(new Entity(200,200));

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED); //creation renderer





    Loading_Surf = SDL_LoadBMP("Spielfeld.bmp");

    Background = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);

    SDL_RenderCopy(Renderer, Background, NULL, NULL);

    SDL_FreeSurface(Loading_Surf);




    const char *super1 = "hughes_20-20.bmp";


    Stock[0]->loadbild(Renderer, super1);
    Stock[1]->loadbild(Renderer, super1);
    Stock[0]->render(Renderer);
    Stock[1]->render(Renderer);
    SDL_RenderPresent(Renderer);





    return true;
}
