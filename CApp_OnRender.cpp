#include "Capp.h"

void Capp::OnRender() {




            SDL_RenderCopy(Renderer, Background, NULL, NULL);

            Stock[0]->render(Renderer);
            Stock[1]->render(Renderer);

            SDL_RenderPresent(Renderer);



}
