#include "entity.h"
#include <string.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "math.h"
#include "capp.h"

#define PI 3.14159265

Entity::Entity()
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    new_Cap = 4;
    angle = 0;

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = 100;
    dest_test.y = 100;
    dest_test.w = 20;
    dest_test.h = 20;
}

Entity::Entity(EEntity aircraft, int xposition, int yposition, SDL_Renderer* moi)
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    new_Cap = 4;
    angle = 0;
    printf("%d", aircraft);


    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = xposition;
    dest_test.y = yposition;

    switch(aircraft)
    {
        case 2:
        dest_test.w = 25;
        dest_test.h = 25;
        break;

        case 0:
        dest_test.w = 30;
        dest_test.h = 30;
        break;

        default:
        dest_test.w = 40;
        dest_test.h = 40;
        break;

    }


    switch(aircraft)
    {
        case 2:
        Loading_Surf_Entity = IMG_Load("hughes_25-25.png");
        break;

        case 0:
        Loading_Surf_Entity = IMG_Load("Pitts_23-23.png");
        break;

        default:
        Loading_Surf_Entity = IMG_Load("A380_30-30.png");
        break;

    }




    if( Loading_Surf_Entity == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Entity.png", IMG_GetError() );
	}
	else
	{
		SDL_QueryTexture(Bild, NULL, NULL, &dest_test.w, &dest_test.h);
                                                                                                //Create texture from surface
        Bild = SDL_CreateTextureFromSurface(moi, Loading_Surf_Entity);
		if( Bild == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Entity.png", SDL_GetError() );
		}


		SDL_FreeSurface(Loading_Surf_Entity);
	}

}

Entity::~Entity()
{
    //dtor
}

SDL_Texture* Entity::getBild()
{
    return Bild;
}

void Entity::setBild(SDL_Texture* truc)
{

    Bild = truc;
}

SDL_Rect Entity::getsrc_test()
{
    return src_test;
}

void Entity::setsrc_test(SDL_Rect truc)
{

    src_test = truc;
}

SDL_Rect Entity::getdest_test()
{
    return dest_test;
}

void Entity::setdest_test(SDL_Rect truc)
{
    dest_test = truc;
}

bool Entity::crash(SDL_Rect a,SDL_Rect b)
{


}
void Entity::fly(int cap)
{




    printf("cap:%d\n",cap);
/*
    if (cap != new_Cap)         //difference of cap
    {


        new_Cap = cap;

    switch(new_Cap)             //between 0 and 15
         {

             case 0:
                new_Posx = 0;
                new_Posy = 2;
                angle = 90;
             break;

             case 1:
                new_Posx = 1;
                new_Posy = 2;
                angle = 67.5;
             break;

             case 2:
                new_Posx = 2;
                new_Posy = 2;
                angle = 45;
             break;

             case 3:
                new_Posx = 2;
                new_Posy = 1;
                angle = 22.5;
             break;

             case 4:
                new_Posx = 2;
                new_Posy = 0;
                angle = 0;
             break;

             case 5:
                new_Posx = 2;
                new_Posy = -1;
                angle = 337.5;
             break;

             case 6:
                new_Posx = 2;
                new_Posy = -2;
                angle = 315;
             break;

             case 7:
                new_Posx = 1;
                new_Posy = -2;
                angle = 292.5;
             break;

             case 8:
                new_Posx = 0;
                new_Posy = -2;
                angle = 270;
             break;

             case 9:
                new_Posx = -1;
                new_Posy = -2;
                angle = 247.5;
             break;

             case 10:
                new_Posx = -2;
                new_Posy = -2;
                angle = 225;
             break;

             case 11:
                new_Posx = -2;
                new_Posy = -1;
                angle = 202.5;
             break;

             case 12:
                new_Posx = -2;
                new_Posy = 0;
                angle = 180;
             break;

             case 13:
                new_Posx = -2;
                new_Posy = 1;
                angle = 157.5;
             break;

             case 14:
                new_Posx = -2;
                new_Posy = 2;
                angle = 135;
             break;

             case 15:
                new_Posx = -1;
                new_Posy = 2;
                angle = 112.5;
             break;


             break;
         }



    }
*/

        angle = cap;
        dest_test.x += cos( cap * PI / 180.0 )* 5 *sqrt((pow(cos(cap),2))+(pow(sin(cap),2)));
        if ((dest_test.x <0) || (dest_test.x>1900))
        {
            dest_test.x -= cos( cap * PI / 180.0 )* 5 *sqrt((pow(cos(cap),2))+(pow(sin(cap),2)));
        }
        dest_test.y += sin( cap * PI / 180.0 )* 5 *sqrt((pow(cos(cap),2))+(pow(sin(cap),2)));
        if ((dest_test.y <0) || (dest_test.y>1035))
        {
            dest_test.y -= sin( cap * PI / 180.0 )* 5 *sqrt((pow(cos(cap),2))+(pow(sin(cap),2)));
        }
}

void Entity::render(SDL_Renderer* Renderer)
{

    SDL_RenderCopyEx(Renderer, Bild, &src_test, &dest_test, angle, NULL, SDL_FLIP_NONE);

}

void Entity::loadbild(SDL_Renderer* Renderer, const char *image)
{

    Loading_Surf_Entity = IMG_Load(image);

    if( Loading_Surf_Entity == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Entity.png", IMG_GetError() );
	}
	else
	{
		SDL_QueryTexture(Bild, NULL, NULL, &dest_test.w, &dest_test.h);         //Create texture from surface
        Bild = SDL_CreateTextureFromSurface(Renderer, Loading_Surf_Entity);
		if( Bild == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Entity.png", SDL_GetError() );
		}


		SDL_FreeSurface(Loading_Surf_Entity);
	}
}


