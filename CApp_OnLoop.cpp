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
            Stock[i]->set_infos(&data);
            std::cout<<data<<std::endl;
            message = TTF_RenderText_Solid( font, data.c_str(), textColor );
            text = SDL_CreateTextureFromSurface(Renderer,message);
            SDL_QueryTexture(text, NULL, NULL, &w, &h);
            textRect.x=1500;textRect.y=100;textRect.w=w;textRect.h=h;
        }
        else
        {
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
    }
}
