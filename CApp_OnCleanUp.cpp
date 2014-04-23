#include "Capp.h"

void Capp::OnCleanup(){

    if(Renderer) {
            SDL_DestroyRenderer(Renderer);
            Renderer = NULL;
        }

    if(Surf_Display) {
            SDL_DestroyWindow(Surf_Display);
            Surf_Display = NULL;
        }


    SDL_Quit();
}
