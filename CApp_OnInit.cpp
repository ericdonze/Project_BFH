#include "Capp.h"

bool Capp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {         //initialisation SDL
        return false;
    }

     if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) { //
        return false;
    }

    if((Window = SDL_CreateWindow("My SDL Game",    //creation main-window
     0, 50,
     WindowWidth, WindowHeight, 0)) == NULL) {
        return false;
    }


    Stock.push_back(new Entity());
    Stock.push_back(new Entity(200,200));

    button.push_back(new Button());
    button.push_back(new Button(0,0));
    button.push_back(new Button());
    button.push_back(new Button(0,0));


    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED); //creation renderer





    Loading_Surf = SDL_LoadBMP("Spielfeld.bmp");

    Background_1 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);

    SDL_RenderCopy(Renderer, Background_1, NULL, NULL);

    SDL_FreeSurface(Loading_Surf);


    Loading_Surf = SDL_LoadBMP("Homescreen.bmp");

    Background_2 = SDL_CreateTextureFromSurface(Renderer, Loading_Surf);

    SDL_RenderCopy(Renderer, Background_2, NULL, NULL);

    SDL_FreeSurface(Loading_Surf);


    const char *super1 = "hughes_20-20.bmp";
    const char *button_1 = "button_1.bmp";


    button[0]->loadbild(Renderer, button_1);
    button[1]->loadbild(Renderer, button_1);
    button[2]->loadbild(Renderer, button_1);
    button[0]->position(0,0);
    button[1]->position(100,100);
    button[2]->position(200,200);
    button[0]->render(Renderer);
    button[1]->render(Renderer);
    button[2]->render(Renderer);


    Stock[0]->loadbild(Renderer, super1);
    Stock[1]->loadbild(Renderer, super1);
    Stock[0]->render(Renderer);
    Stock[1]->render(Renderer);
    SDL_RenderPresent(Renderer);





    return true;
}
