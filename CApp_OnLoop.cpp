#include "Capp.h"
#include "entity.h"

void Capp::OnLoop() {
    if(SDL_GetTicks()- waitTime > tick)//creat all ticktime a aircraft
    {
        OnCreate();
        waitTime=SDL_GetTicks();
        if(tick>1000)//make the tick time smaller but not under 1sec
        {
            tick-=tick/40;
        }
    }
    for(unsigned int i=0;i<Stock.size();i++)
    {
        if(Stock[i]->get_On_click()==true)//Just when the aircraft is marked
        {
            if(winkel!=Stock[i]->get_cap_next())
            {
                Stock[i]->fly(winkel,1);//give the new cap
            }
            else
            {
                Stock[i]->fly(Stock[i]->get_cap_next(),0);//go to the old cap
            }
            Stock[i]->set_infos(&data_1);//give the aircraft information back
            message_1 = TTF_RenderText_Solid( font_1, data_1.c_str(), textColor );
            text_1 = SDL_CreateTextureFromSurface(Renderer,message_1);
            SDL_QueryTexture(text_1, NULL, NULL, &w, &h);
            textRect.x=Stock[i]->get_x_position()+20;textRect.y=Stock[i]->get_y_position()-20;textRect.w=w;textRect.h=h;
            data_old=1;
        }
        else
        {
            z++;
            Stock[i]->fly(Stock[i]->get_cap_next(),0);//let the aircraft fly
        }
        if(Stock[i]->land(Stock)==1)//check if the aircraft is landing
        {
            score += Stock[i]->game_point();
            Stock[i]->set_On_click(0);
            delete Stock[i];
            Stock.erase(Stock.begin()+i);
        }
        if(Stock[i]->crash(Stock,i)==1)// check if the aircraft is crashing
        {
            Mix_PlayChannel( -1, gcrash, 0 );
            OnAnimation(Stock[i]->get_x_position(),Stock[i]->get_y_position());
            SDL_Delay(300);
            if(cnt_point == 0)//write the score
            {
                cnt_point = 1;
                monFlux_I.open("highscore.txt"); // Open the file stream in Input Mode
                if(monFlux_I)
                {
                    monFlux_I >> highscore; //read the score in the file

                }
                else
                {
                    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
                }
                monFlux_I.close();
                if(score > highscore)
                {
                    monFlux_O.open("highscore.txt");    // Open the file stream in Output Mode
                    if(monFlux_O)
                    {
                        monFlux_O << score << endl;
                    }
                    else
                    {
                        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
                    }
                    monFlux_O.close();
                }
                ss_2 << score;
                ss << highscore;
            }
            else
            {
                //if it's the second crash
            }

            Menu=Spielendcard;
        }
        if(!Stock[i]->inside_playfield())//check if the aircraft is left the playfield
        {
            score += Stock[i]->game_point();
            delete Stock[i];
            Stock.erase(Stock.begin()+i);
        }
    }
    if(z==Stock.size())
    {
        if (data_old==1)// when no aircraft is marked then it write nothing on the screen
        {
            data_1="";
            message_1 = TTF_RenderText_Solid( font_1, data_1.c_str(), textColor );
            text_1 = SDL_CreateTextureFromSurface(Renderer,message_1);
            SDL_QueryTexture(text_1, NULL, NULL, &w, &h);
            textRect.x=1500;textRect.y=100;textRect.w=w;textRect.h=h;
            data_old=0;
        }
    }
    z=0;
}
