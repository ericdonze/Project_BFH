#include "Capp.h"
#include <SDL_image.h>

void Capp::OnCleanup(){
    Stock.clear();
    button.clear();

    if(Background_1) {
            SDL_DestroyTexture(Background_1);
            Background_1 = NULL;
        }

    if(Background_2) {
            SDL_DestroyTexture(Background_2);
            Background_2 = NULL;
        }
    if(Background_3) {
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

    IMG_Quit();
    SDL_Quit();
}
