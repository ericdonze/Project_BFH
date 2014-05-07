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
    message_1 = NULL;
    font = NULL;
    text=NULL;
    text_1=NULL;
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
