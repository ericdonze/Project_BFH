#include "Capp.h"
#include <SDL_image.h>

void Capp::OnCleanup(){
    Stock.clear();  //clear the vector Stock
    button.clear(); //clear the vector button

    if(Background_1) {
            SDL_DestroyTexture(Background_1);   //clear the texture
            Background_1 = NULL;
        }

    if(Background_2) {
            SDL_DestroyTexture(Background_2);   //clear the texture
            Background_2 = NULL;
        }
    if(Background_3) {
            SDL_DestroyTexture(Background_3);   //clear the texture
            Background_3 = NULL;
        }

   if(Sprite) {
            SDL_FreeSurface(Sprite);        //clear the Surface
            Sprite = NULL;
        }

    if(Renderer) {
            SDL_DestroyRenderer(Renderer);  //clear the Renderer
            Renderer = NULL;
        }

    if(Window) {
            SDL_DestroyWindow(Window);  //clear the window
            Window = NULL;
        }

    IMG_Quit();     //close SDL_IMG
    SDL_Quit();     //close SDL library
}
