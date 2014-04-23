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

							case SDLK_a:
							Cap_next1 += 1;
							break;

							case SDLK_d:
							Cap_next1 -= 1;
							break;

							case SDLK_LEFT:
							Cap_next2 += 1;
							break;

							case SDLK_RIGHT:
							Cap_next2 -= 1;
							break;

							break;

                        }

                        if(Cap_next1 < 0)                //keep Cap_next between 0 and 15
                                {
                                    Cap_next1 += 16;
                                }
                                else if(Cap_next1 > 15)
                                {
                                    Cap_next1 -=16;
                                }

                                if(Cap_next2 < 0)                //keep Cap_next between 0 and 15
                                {
                                    Cap_next2 += 16;
                                }
                                else if(Cap_next2 > 15)
                                {
                                    Cap_next2 -=16;
                                }

                    }
                    else if( Event.type == SDL_MOUSEBUTTONDOWN )
                    {
                        Cap_next2 += 1;
                        //SDL_GetMouseState( &x_mouse, &y_mouse ); Gibt die Mouseposition heraus

                        /*vector_x=x_mouse-DestR.x;             Misst denn winkel des Vectors zwischen Objekt und Maus
                        vector_y=DestR.y-y_mouse;
                        winkel=(atan2(vector_y, vector_x)*(180/3.14159));
                        if(winkel<0)
                        {
                            winkel+=360;
                        }
                        printf("%f/%fwinkel=%f\n",vector_y,vector_x,winkel);*/
                    }



        }



        OnLoop();       //all calcul
        OnRender();     //all draw
        SDL_Delay(50);  //wait

}






    OnCleanup();       //clean SDL tools



    return 0;
}

int main(int argc, char* argv[]) {

    Capp theApp;


    return theApp.OnExecute();
}
