#include "Capp.h"

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
                case SDLK_p:
                    Menu=Spielendcard;
                    break;
                case SDLK_ESCAPE:
                    Running=0;
                    break;
                case SDLK_a:
                    Cap_next1 -= 4;
                    break;
                case SDLK_d:
                    Cap_next1 += 4;
                    break;
                case SDLK_LEFT:
                    Cap_next2 -= 4;
                    break;
                case SDLK_RIGHT:
                    Cap_next2 += 4;
                    break;
            }
            if(Cap_next1 < 1)                //keep Cap_next between 0 and 15
            {
                Cap_next1 += 359;
            }
            else if(Cap_next1 > 359)
            {
                Cap_next1 -=360;
            }

            if(Cap_next2 < 1)                //keep Cap_next between 0 and 15
            {
                Cap_next2 += 359;
            }
            else if(Cap_next2 > 359)
            {
                Cap_next2 -=360;
            }

        }
        else if( Event->type == SDL_MOUSEBUTTONDOWN )
        {



            if((Event->button.button == SDL_BUTTON_LEFT))// left mouse click
            {




            SDL_GetMouseState( &mouse_x, &mouse_y ); //Gibt die Mouseposition heraus
            if(Menu==Hauptmenu)
            {
                if(mouse_x>button[0]->get_x_position()&&mouse_x<button[0]->get_x_position()+button[0]->get_breite()&&mouse_y>button[0]->get_y_position()&&mouse_y<button[0]->get_y_position()+button[0]->get_hoehe())
                {
                    Menu=Spielablauf;
                }
                if(mouse_x>button[1]->get_x_position()&&mouse_x<button[1]->get_x_position()+button[1]->get_breite()&&mouse_y>button[1]->get_y_position()&&mouse_y<button[1]->get_y_position()+button[1]->get_hoehe())
                {
                    Running=0;
                }
            }
            else if(Menu==Spielablauf)
            {
                if(mouse_x>Stock[0]->get_x_position()&&mouse_x<Stock[0]->get_x_position()+Stock[0]->get_width()&&mouse_y>Stock[0]->get_y_position()&&mouse_y<Stock[0]->get_y_position()+Stock[0]->get_height())
                {
                    Stock[0]->set_On_click(1);
                }

                else
                {
                    Stock[0]->set_On_click(0);
                }

            }

            else if(Menu==Spielendcard)
            {
                if(mouse_x>button[2]->get_x_position()&&mouse_x<button[2]->get_x_position()+button[2]->get_breite()&&mouse_y>button[2]->get_y_position()&&mouse_y<button[2]->get_y_position()+button[2]->get_hoehe())
                {
                    Menu=Hauptmenu;
                }
                if(mouse_x>button[3]->get_x_position()&&mouse_x<button[3]->get_x_position()+button[3]->get_breite()&&mouse_y>button[3]->get_y_position()&&mouse_y<button[3]->get_y_position()+button[3]->get_hoehe())
                {
                    Menu=Spielablauf;
                }
            }

        }
        else if((Event->button.button == SDL_BUTTON_RIGHT))
        {
            //right click
        }

                        /*vector_x=x_mouse-DestR.x;             Misst denn winkel des Vectors zwischen Objekt und Maus
                        vector_y=DestR.y-y_mouse;
                        winkel=(atan2(vector_y, vector_x)*(180/3.14159));
                        if(winkel<0)
                        {
                            winkel+=360;
                        }
                        printf("%f/%fwinkel=%f\n",vector_y,vector_x,winkel);*/
        }
        else if( Event->type == SDL_MOUSEMOTION )
        {
            SDL_GetMouseState( &mouse_x, &mouse_y ); //Gibt die Mouseposition heraus
            if(Menu==Hauptmenu||Menu==Spielendcard)
            {
                if(mouse_x>button[0]->get_x_position()&&mouse_x<button[0]->get_x_position()+button[0]->get_breite()&&mouse_y>button[0]->get_y_position()&&mouse_y<button[0]->get_y_position()+button[0]->get_hoehe())
                {
                    Taster_0=1;
                }
                else
                {
                    Taster_0=0;
                }
                if(mouse_x>button[1]->get_x_position()&&mouse_x<button[1]->get_x_position()+button[1]->get_breite()&&mouse_y>button[1]->get_y_position()&&mouse_y<button[1]->get_y_position()+button[1]->get_hoehe())
                {
                    Taster_1=1;
                }
                else
                {
                    Taster_1=0;
                }
                if(mouse_x>button[2]->get_x_position()&&mouse_x<button[2]->get_x_position()+button[2]->get_breite()&&mouse_y>button[2]->get_y_position()&&mouse_y<button[2]->get_y_position()+button[2]->get_hoehe())
                {
                    Taster_2=1;
                }
                else
                {
                    Taster_2=0;
                }
                if(mouse_x>button[3]->get_x_position()&&mouse_x<button[3]->get_x_position()+button[3]->get_breite()&&mouse_y>button[3]->get_y_position()&&mouse_y<button[3]->get_y_position()+button[3]->get_hoehe())
                {
                    Taster_3=1;
                }
                else
                {
                    Taster_3=0;
                }
            }
            //printf("x=%d,y=%d,w=%d,h=%d\n",button[0]->get_x_position(),button[0]->get_y_position(),button[0]->get_breite(),button[0]->get_hoehe());
        }

}
