#include "Capp.h"

void Capp::OnRender_1() {




            SDL_RenderCopy(Renderer, Background_1, NULL, NULL);
            Stock[0]->render(Renderer);
            Stock[1]->render(Renderer);


            SDL_RenderPresent(Renderer);



}
void Capp::OnRender_2() {
            SDL_RenderCopy(Renderer, Background_2, NULL, NULL);
            button[0]->render(Renderer,Taster_0);
            button[1]->render(Renderer,Taster_1);


            SDL_RenderPresent(Renderer);
}
void Capp::OnRender_3()
{
            SDL_RenderCopy(Renderer, Background_3, NULL, NULL);
            button[1]->render(Renderer,Taster_1);
            button[2]->render(Renderer,Taster_2);
            button[3]->render(Renderer,Taster_3);


            SDL_RenderPresent(Renderer);
}
