#include "Capp.h"

void Capp::OnLoop() {


    for(int i=0;i<Stock.size();i++)
    {
        if(Stock[i]->get_On_click()==true)
        {
            if(winkel!=Stock[i]->get_cap_next())
            {
                Stock[i]->fly(winkel,1);
            }
            else
            {
                Stock[i]->fly(Stock[i]->get_cap_next(),0);
            }
            Stock[i]->set_infos(&data_1);
            std::cout<<data_1<<std::endl;
            message_1 = TTF_RenderText_Solid( font_1, data_1.c_str(), textColor );
            text_1 = SDL_CreateTextureFromSurface(Renderer,message_1);
            SDL_QueryTexture(text_1, NULL, NULL, &w, &h);
            textRect.x=Stock[i]->get_x_position()+20;textRect.y=Stock[i]->get_y_position()-20;textRect.w=w;textRect.h=h;
        }
        else
        {
            z++;
            Stock[i]->fly(Stock[i]->get_cap_next(),0);
        }

        if(Stock[i]->land(Stock)==1)
        {
            printf("landing succeeded");
        }

        if(Stock[i]->crash(Stock,i)==1)
        {
            Menu=Spielendcard;
        }
        if(!Stock[i]->inside_playfield())
        {
            delete Stock[i];
            Stock.erase(Stock.begin()+i);
        }
    }
    if(z==Stock.size())
    {
        data_1="";
        std::cout<<data_1<<std::endl;
        message_1 = TTF_RenderText_Solid( font_1, data_1.c_str(), textColor );
        text_1 = SDL_CreateTextureFromSurface(Renderer,message_1);
        SDL_QueryTexture(text_1, NULL, NULL, &w, &h);
        textRect.x=1500;textRect.y=100;textRect.w=w;textRect.h=h;
    }
    z=0;

}
