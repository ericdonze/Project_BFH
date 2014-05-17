#include "Capp.h"

void Capp::OnRender_1() {




            SDL_RenderCopy(Renderer, Background_1, NULL, NULL);
            for(i=0;i<Stock.size();i++)
            {
                Stock[i]->render(Renderer);
            }
            std::cout<<data<<std::endl;
            message = TTF_RenderText_Solid( font, data.c_str(), textColor );
            text = SDL_CreateTextureFromSurface(Renderer,message);
            SDL_QueryTexture(text, NULL, NULL, &w, &h);
            textRect.x=1500;textRect.y=100;textRect.w=w;textRect.h=h;
            SDL_RenderCopy(Renderer, text, NULL, &textRect);

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
