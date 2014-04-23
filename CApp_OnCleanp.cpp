#include "Capp.h"

void Capp::OnCleanup(){

    if(Background) {
            SDL_DestroyTexture(Background);
            Background = NULL;
        }


   if(Sprite) {
            SDL_FreeSurface(Sprite);
            Sprite = NULL;
        }

    if(Renderer) {
            SDL_DestroyRenderer(Renderer);
            Renderer = NULL;
        }

    if(Window) {
            SDL_DestroyWindow(Window);
            Window = NULL;
        }


    SDL_Quit();
}
