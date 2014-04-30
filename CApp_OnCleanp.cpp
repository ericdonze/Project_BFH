#include "Capp.h"

void Capp::OnCleanup(){

    if(Background_1) {
            SDL_DestroyTexture(Background_1);
            Background_1 = NULL;
        }

    if(Background_2) {
            SDL_DestroyTexture(Background_2);
            Background_2 = NULL;
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
