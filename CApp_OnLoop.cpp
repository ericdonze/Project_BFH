#include "Capp.h"
#include "entity.h"

void Capp::OnLoop() {
    if(SDL_GetTicks()- waitTime > tick)
    {
        OnCreate();
        waitTime=SDL_GetTicks();
        if(tick>1000)
        {
            tick-=tick/40;
        }
    }


    for(unsigned int i=0;i<Stock.size();i++)
    {
        if(Stock[i]->get_On_click()==true)
        {
            Stock[i]->set_window_size(WindowWidth,WindowHeight);
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
            data_old=1;
        }
        else
        {
            z++;
            Stock[i]->fly(Stock[i]->get_cap_next(),0);
        }

        if(Stock[i]->land(Stock)==1)
        {
            score += Stock[i]->game_point();
            Stock[i]->set_On_click(0);
            delete Stock[i];
            Stock.erase(Stock.begin()+i);
        }
        if(Stock[i]->crash(Stock,i)==1)
        {
            Mix_PlayChannel( -1, gcrash, 0 );
            OnAnimation(Stock[i]->get_x_position(),Stock[i]->get_y_position());
            SDL_Delay(300);
            if(cnt_point == 0)
            {
                cnt_point = 1;
                monFlux_I.open("highscore.txt");
                if(monFlux_I)  //On teste si tout est OK
                {
                    monFlux_I >> highscore;
                    cout << highscore << endl;
                }
                else
                {
                    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
                }
                monFlux_I.close();
                if(score > highscore)
                {
                    monFlux_O.open("highscore.txt");
                    if(monFlux_O)  //On teste si tout est OK
                    {
                        monFlux_O << score << endl;
                        ss << score;
                    }
                    else
                    {
                        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
                    }
                    monFlux_O.close();
                }
                else
                {

                    ss << highscore;
                }
            }
            else
            {
                //if it's the second crash
            }
            cout << "stream: " << ss <<endl;

            Menu=Spielendcard;
        }
        if(!Stock[i]->inside_playfield())
        {
            score += Stock[i]->game_point();
            delete Stock[i];
            Stock.erase(Stock.begin()+i);
        }
    }
    if(z==Stock.size())
    {
        if (data_old==1)
        {
        data_1="";
        std::cout<<data_1<<std::endl;
        message_1 = TTF_RenderText_Solid( font_1, data_1.c_str(), textColor );
        text_1 = SDL_CreateTextureFromSurface(Renderer,message_1);
        SDL_QueryTexture(text_1, NULL, NULL, &w, &h);
        textRect.x=1500;textRect.y=100;textRect.w=w;textRect.h=h;
        data_old=0;
        }
    }
    z=0;
}
