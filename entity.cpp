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
    new_cap = 4;
    angle = 0;
    On_click = 0;

    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = 100;
    dest_test.y = 100;
    dest_test.w = 20;
    dest_test.h = 20;
}

Entity::Entity(EEntity aircraft,IEntity Infos, int xposition, int yposition, SDL_Renderer* moi)
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    new_cap = 4;
    angle = 0;
    On_click = 0;



    src_test.x = 0;
    src_test.y = 0;
    src_test.w = 200;
    src_test.h = 200;

    dest_test.x = xposition;
    dest_test.y = yposition;
    switch(Infos)
    {
        case 0:
            Info_Flugzeug="Flugzeug Landen";
        break;

        case 1:
            Info_Flugzeug="Flugzeug Links weg";
        break;

        case 2:
            Info_Flugzeug="Flugzeug Rechts weg";
        break;
        case 3:
            Info_Flugzeug="Flugzeug Oben weg";
        break;
        case 4:
           Info_Flugzeug="Flugzeug Unten weg";
        break;

    }
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





	Loading_Surf_Entity = IMG_Load("cercle_rouge.png");

	if( Loading_Surf_Entity == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Cercle.png", IMG_GetError() );
	}
	else
	{
		SDL_QueryTexture(Cercle, NULL, NULL, &dest_test.w, &dest_test.h);
                                                                                                //Create texture from surface
        Cercle = SDL_CreateTextureFromSurface(moi, Loading_Surf_Entity);
		if( Cercle == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Cercle.png", SDL_GetError() );
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
int Entity::get_x_position()
{
    return dest_test.x;
}
int Entity::get_y_position()
{
    return dest_test.y;
}
int Entity::get_width()
{
    return dest_test.w;
}
int Entity::get_height()
{
    return dest_test.h;
}
void Entity::set_infos(std::string* p)
{
    *p=Info_Flugzeug;

}
double Entity::get_cap_next()
{
    return angle;
}
char Entity::inside_entity(int mouse_x, int mouse_y)
{
    if(mouse_x>dest_test.x-20&&mouse_x<dest_test.x+dest_test.w+20&&mouse_y>dest_test.y-20&&mouse_y<dest_test.y+dest_test.h+20)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Entity::precrash(std::vector<Entity*> Stock,int  cap1, int cap2)
{
    int virt_x0=Stock[0]->getdest_test().x;
    int virt_y0=Stock[0]->getdest_test().y;
    int virt_x1=Stock[1]->getdest_test().x;
    int virt_y1=Stock[1]->getdest_test().y;


    for(int i=0;i<20;i++)
    {
        virt_x0 += cos( cap1 * PI / 180.0 )* 5 *sqrt((pow(cos(cap1),2))+(pow(sin(cap1),2)));
        virt_y0 += sin( cap1 * PI / 180.0 )* 5 *sqrt((pow(cos(cap1),2))+(pow(sin(cap1),2)));
        virt_x1 += cos( cap2 * PI / 180.0 )* 5 *sqrt((pow(cos(cap2),2))+(pow(sin(cap2),2)));
        virt_y1 += sin( cap2 * PI / 180.0 )* 5 *sqrt((pow(cos(cap2),2))+(pow(sin(cap2),2)));

        if (((virt_x0 + dest_test.w < virt_x1)
            || (virt_x0 > virt_x1 + Stock[1]->getdest_test().w)
            || ((virt_y0 + dest_test.h < virt_y1)
            || (virt_y0 > virt_y1 + Stock[1]->getdest_test().h))))
        {
            return false;
        }


       else
        {

        return true;

       }
    }


}
bool Entity::land(std::vector<Entity*> Stock)
{
    if(((dest_test.x + dest_test.w < 600)
        || (dest_test.x > 620)
        || (dest_test.y + dest_test.h < 252)
        || (dest_test.y > 232))
        &&  (new_cap>300
        ||  new_cap<330))
    {

        return false;
    }
    else
    {
        return true;

    }
}
bool Entity::crash(std::vector<Entity*> Stock, int n)
{
    int i;
    for(i=0;i<Stock.size();i++)
    {
        if (((dest_test.x + dest_test.w < Stock[1]->getdest_test().x)
            || (dest_test.x > Stock[1]->getdest_test().x + Stock[1]->getdest_test().w)
            || ((dest_test.y + dest_test.h < Stock[1]->getdest_test().y)
            || (dest_test.y > Stock[1]->getdest_test().y + Stock[1]->getdest_test().h))))
        {
            return false;
        }


       else
        {
            if(i=!n)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
void Entity::fly(int cap,char go)
{
    if(go==1)
    {
        delta_cap=new_cap-cap;
        if(delta_cap<0)
        {
            delta_cap+=360;
        }
        if(delta_cap>180)
        {
            new_cap+=3;
        }
        else
        {
            new_cap-=3;
        }
        if(((delta_cap<4)&&(delta_cap>0))||(delta_cap>356))
        {
            new_cap=cap;
        }

        if(new_cap>360)
        {
            new_cap-=360;
        }
        if(new_cap<0)
        {
            new_cap+=360;
        }

        printf("new_cap=%d delta_cap=%d\n",new_cap,delta_cap);
    }
    else
    {
        new_cap=cap;
    }
    angle = new_cap;
    dest_test.x += cos( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap),2))+(pow(sin(new_cap),2)));
    if ((dest_test.x <0) || (dest_test.x>1900))
    {
        dest_test.x -= cos( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap),2))+(pow(sin(new_cap),2)));
    }
    dest_test.y += sin( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap),2))+(pow(sin(new_cap),2)));
    if ((dest_test.y <0) || (dest_test.y>1035))
    {
        dest_test.y -= sin( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap),2))+(pow(sin(new_cap),2)));
    }

}

void Entity::render(SDL_Renderer* Renderer)
{

    SDL_RenderCopyEx(Renderer, Bild, &src_test, &dest_test, angle, NULL, SDL_FLIP_NONE);

    if(On_click == 1)
    {
        SDL_RenderCopyEx(Renderer, Cercle, &src_test, &dest_test, angle, NULL, SDL_FLIP_NONE);
    }
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

bool Entity::get_On_click()
{
    return On_click;
}

void Entity::set_On_click(bool click)
{
    On_click = click;
}
