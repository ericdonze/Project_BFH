#include "Capp.h"
#include "math.h"

void Capp::OnEvent(SDL_Event* Event)
{

        if(Event->type == SDL_QUIT)
        {    //cross up-right
            Running = false;
        }

        else if( Event->type == SDL_KEYDOWN ) //all key-touch
        {
            switch( Event->key.keysym.sym )// which key
            {
                case SDLK_ESCAPE:
                    if(Menu==Spielablauf)
                    {
                        Menu=Spielendcard;
                    }
                    else
                    {
                        Running=0;
                    }
                    break;
                case SDLK_a:
                    winkel -= 4;
                    break;
                case SDLK_d:
                    winkel += 4;
                    break;
            }
            if(winkel < 1)                //keep Cap_next between 0 and 15
            {
                winkel += 359;
            }
            else if(winkel > 359)
            {
                winkel -=360;
            }

        }
        else if( Event->type == SDL_MOUSEBUTTONDOWN )
        {

            if((Event->button.button == SDL_BUTTON_LEFT))// left mouse click
            {

                SDL_GetMouseState( &mouse_x, &mouse_y ); //Give the mouse position
                if(Menu==Hauptmenu)
                {
                    //check if the buttons are clicked
                    if(button[0]->inside_button(mouse_x,mouse_y)==true)
                    {
                        Menu=Spielablauf;
                        OnRestart();
                    }
                    if(button[1]->inside_button(mouse_x,mouse_y)==true)
                    {
                        Running=0;
                    }
                }
                else if(Menu==Spielablauf)
                {
                    //check all aircraft and mark it
                    for(i=0;i<Stock.size();i++)
                    {
                        if(Stock[i]->inside_entity(mouse_x,mouse_y)==true)
                        {
                            if(Stock[i]->get_On_click()==true)
                            {
                                Stock[i]->set_On_click(0);
                            }
                            else
                            {
                                OnPilotFunk();
                                Stock[i]->set_On_click(1);
                                winkel=Stock[i]->get_cap_next();
                            }
                        }
                        else
                        {
                            if(Stock[i]->get_On_click()==true)
                            {
                                Stock[i]->set_On_click(0);
                            }
                        }
                    }

                }

                else if(Menu==Spielendcard)
                {
                    //check all button if the are clicked
                    if(button[1]->inside_button(mouse_x,mouse_y)==true)
                    {
                        Running=0;
                    }
                    if(button[2]->inside_button(mouse_x,mouse_y)==true)
                    {
                        Menu=Hauptmenu;
                        OnRestart();

                    }
                    if(button[3]->inside_button(mouse_x,mouse_y)==true)
                    {
                        OnRestart();
                        Menu=Spielablauf;
                    }
                }

            }
            else if((Event->button.button == SDL_BUTTON_RIGHT))
            {
                //calculated the angel for the aircraft
                if(Menu==Spielablauf)
                {
                    for(i=0;i<Stock.size();i++)
                    {
                        if(Stock[i]->get_On_click()==true&&Stock[i]->inside_entity(mouse_x,mouse_y)==false)
                        {
                            vector_x=mouse_x-(Stock[i]->get_x_position()+Stock[i]->get_width()/2);            // Misst denn winkel des Vectors zwischen Objekt und Maus
                            vector_y=mouse_y-(Stock[i]->get_y_position()+Stock[i]->get_height()/2);
                            winkel=(atan2(vector_y, vector_x)*(180/3.14159));
                            if(winkel<0)
                            {
                                winkel+=360;
                            }
                            printf("winkel=%d\n",winkel);
                        }
                    }
                }
                //right click
            }
        }
        else if( Event->type == SDL_MOUSEMOTION )
        {
            SDL_GetMouseState( &mouse_x, &mouse_y );//give the mouse position back
            if(Menu==Hauptmenu||Menu==Spielendcard)
            {
                //make the special effect from the button
                if(button[0]->inside_button(mouse_x,mouse_y)==true)
                {
                    Taster_0=1;
                }
                else
                {
                    Taster_0=0;
                }
                if(button[1]->inside_button(mouse_x,mouse_y)==true)
                {
                    Taster_1=1;
                }
                else
                {
                    Taster_1=0;
                }
                if(button[2]->inside_button(mouse_x,mouse_y)==true)
                {
                    Taster_2=1;
                }
                else
                {
                    Taster_2=0;
                }
                if(button[3]->inside_button(mouse_x,mouse_y)==true)
                {
                    Taster_3=1;
                }
                else
                {
                    Taster_3=0;
                }
            }
        }

}
