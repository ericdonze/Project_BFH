#include "Capp.h"

void Capp::OnRender_1() {




            SDL_RenderCopy(Renderer, Background_1, NULL, NULL);
            Stock[0]->render(Renderer);
            Stock[1]->render(Renderer);


            SDL_RenderPresent(Renderer);



}
void Capp::OnRender_2() {
            SDL_RenderCopy(Renderer, Background_2, NULL, NULL);
            button[0]->render(Renderer,Taster_1);
            //button[1]->render(Renderer,Taster_1);


            SDL_RenderPresent(Renderer);
}
