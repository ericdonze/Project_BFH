#include "Capp.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


void Capp::OnRender_1() {




            SDL_RenderCopy(Renderer, Background_1, NULL, NULL);
            for(i=0;i<Stock.size();i++)
            {
                Stock[i]->render(Renderer);
            }

            SDL_RenderCopy(Renderer, text_1, NULL, &textRect);

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

            data_2="Highscore: ";

            string data_3 = ss.str();
            data_final = data_2 + data_3;

            message_2 = TTF_RenderText_Solid( font_2, data_final.c_str(), textColor_2 );
            text_2 = SDL_CreateTextureFromSurface(Renderer,message_2);
            SDL_QueryTexture(text_2, NULL, NULL, &w, &h);
            textRect_2.x=WindowWidth/2-w/2;textRect_2.y=WindowHeight/2-h/2;textRect_2.w=w;textRect_2.h=h;
            SDL_RenderCopy(Renderer, text_2, NULL, &textRect_2);

            //Here ADU !!!!!!!!!!!!!!!!

            SDL_RenderPresent(Renderer);
}
