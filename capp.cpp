#include "capp.h"


Capp::Capp()//ctor
{
    Running = true;
    x_Pos = 0;
    y_Pos = 0;
    Cap_next1 = 3;
    Cap_next2 = 3;
    Cap_now = 0;
    dest = new SDL_Rect;
    src = new SDL_Rect;

    src->x = 0;
    src->y = 0;
    src->w = 200;
    src->h = 200;

    dest->x = 200;
    dest->y = 200;
    dest->w = 100;
    dest->h = 100;

    textColor.r=255;textColor.g=255;textColor.b=255;
    message = NULL;
    font = NULL;
    text=NULL;
}

Capp::~Capp()
{
    //dtor
}

int Capp::OnExecute() {

    if(!OnInit()) return 0;

    SDL_Event Event;

    while(Running) {

        while(SDL_PollEvent(&Event) != 0) // grab events from the event queue, when the queue is empty Pollevent return -1
        {


            OnEvent(&Event);

                if(Event.type == SDL_QUIT)
                {    //cross up-right
                    Running = false;
                }

                else if( Event.type == SDL_KEYDOWN ) //all key-touch
                {
						switch( Event.key.keysym.sym )// which key
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
                    else if( Event.type == SDL_MOUSEBUTTONDOWN )
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
                        }else if(Menu==Spielendcard)
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

                        /*vector_x=x_mouse-DestR.x;             Misst denn winkel des Vectors zwischen Objekt und Maus
                        vector_y=DestR.y-y_mouse;
                        winkel=(atan2(vector_y, vector_x)*(180/3.14159));
                        if(winkel<0)
                        {
                            winkel+=360;
                        }
                        printf("%f/%fwinkel=%f\n",vector_y,vector_x,winkel);*/
                    }else if( Event.type == SDL_MOUSEMOTION )
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
                        printf("x=%d,y=%d,w=%d,h=%d\n",button[0]->get_x_position(),button[0]->get_y_position(),button[0]->get_breite(),button[0]->get_hoehe());
                    }



        }

        switch (Menu)
        {
        case Hauptmenu:
            OnRender_2();
            break;
        case Spielablauf:
            OnLoop();       //all calcul
            OnRender_1();     //all draw
            break;
        case Spielendcard:
            OnRender_3();
            break;
        }

        Test_Box(Renderer);
        SDL_Delay(30);  //wait

}






    OnCleanup();       //clean SDL tools



    return 0;
}

SDL_Renderer* Capp::get_Renderer()
{
    return Renderer;
}

void Capp::Test_Box(SDL_Renderer* box)
{



//    boxRGBA(box, 100, 100, 200, 200, 150, 150, 150, 150);
}



int main(int argc, char* argv[]) {

    Capp theApp;


    return theApp.OnExecute();
}
