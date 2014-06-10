#include "Capp.h"
#include <SDL_image.h>

void Capp::OnAnimation(int x_dest, int y_dest){

    x_dest -= 68;       //that x_dest is in the middle of the image
    y_dest -= 68;       //that y_dest is in the middle of the image

    SpriteRect[0].x = 0;
    SpriteRect[0].y = 0;
    SpriteRect[0].w = 134;
    SpriteRect[0].h = 134;

    SpriteRect[1].x = 134;
    SpriteRect[1].y = 0;
    SpriteRect[1].w = 134;
    SpriteRect[1].h = 134;

    SpriteRect[2].x = 268;
    SpriteRect[2].y = 0;
    SpriteRect[2].w = 134;
    SpriteRect[2].h = 134;

    SpriteRect[3].x = 402;
    SpriteRect[3].y = 0;
    SpriteRect[3].w = 134;
    SpriteRect[3].h = 134;

    SpriteRect[4].x = 536;
    SpriteRect[4].y = 0;
    SpriteRect[4].w = 134;
    SpriteRect[4].h = 134;

    SpriteRect[5].x = 670;
    SpriteRect[5].y = 0;
    SpriteRect[5].w = 134;
    SpriteRect[5].h = 134;

    SpriteRect[6].x = 804;
    SpriteRect[6].y = 0;
    SpriteRect[6].w = 134;
    SpriteRect[6].h = 134;

    SpriteRect[7].x = 938;
    SpriteRect[7].y = 0;
    SpriteRect[7].w = 134;
    SpriteRect[7].h = 134;

    SpriteRect[8].x = 1072;
    SpriteRect[8].y = 0;
    SpriteRect[8].w = 134;
    SpriteRect[8].h = 134;

    SpriteRect[9].x = 1206;
    SpriteRect[9].y = 0;
    SpriteRect[9].w = 134;
    SpriteRect[9].h = 134;

    SpriteRect[10].x = 1340;
    SpriteRect[10].y = 0;
    SpriteRect[10].w = 134;
    SpriteRect[10].h = 134;

    SpriteRect[11].x = 1474;
    SpriteRect[11].y = 0;
    SpriteRect[11].w = 134;
    SpriteRect[11].h = 134;

    Test_anim.x = x_dest;
    Test_anim.y = y_dest;
    Test_anim.w = 134;
    Test_anim.h = 134;

    int i;
    for(i= 1;i<WALKING_ANIMATION_FRAMES;i++)    //for an 12 step animation
    {
        SDL_RenderCopy(Renderer, Sprite_Anim, &SpriteRect[i], &Test_anim);
        SDL_RenderPresent(Renderer);

        SDL_Delay(30);
    }



};
