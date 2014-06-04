#include "entity.h"
#include "Capp.h"
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

    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 200;
    rect_src.h = 200;

    rect_dest.x = 100;
    rect_dest.y = 100;
    rect_dest.w = 20;
    rect_dest.h = 20;
}

Entity::Entity(EEntity aircraft,IEntity Infos, int xposition, int yposition, int cap, SDL_Renderer* moi)
{
    //ctor
    new_Posx = 0;
    new_Posy = 0;
    cap_goto=cap;
    new_cap = cap;
    angle = cap;
    On_click = 0;



    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 200;
    rect_src.h = 200;

    rect_dest.x = xposition;
    rect_dest.y = yposition;

    order = Infos;
    model = aircraft;
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
        rect_dest.w = 25;
        rect_dest.h = 25;
        break;

        case 0:
        rect_dest.w = 30;
        rect_dest.h = 30;
        break;

        default:
        rect_dest.w = 40;
        rect_dest.h = 40;
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
		SDL_QueryTexture(Bild, NULL, NULL, &rect_dest.w, &rect_dest.h);
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
		SDL_QueryTexture(Cercle, NULL, NULL, &rect_dest.w, &rect_dest.h);
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

void Entity::setBild(SDL_Texture* text_bild)
{

    Bild = text_bild;
}

SDL_Rect Entity::getrect_src()
{
    return rect_src;
}

void Entity::setrect_src(SDL_Rect rect_set_src)
{

    rect_src = rect_set_src;
}

SDL_Rect Entity::getrect_dest()
{
    return rect_dest;
}

void Entity::setrect_dest(SDL_Rect rect_set_dest)
{
    rect_dest = rect_set_dest;
}
int Entity::get_x_position()
{
    return rect_dest.x;
}
int Entity::get_y_position()
{
    return rect_dest.y;
}
int Entity::get_width()
{
    return rect_dest.w;
}
int Entity::get_height()
{
    return rect_dest.h;
}
void Entity::set_infos(std::string* p)
{
    *p=Info_Flugzeug;

}
double Entity::get_cap_next()
{
    return angle;
}
bool Entity::inside_entity(int mouse_x, int mouse_y)
{
    if(mouse_x>rect_dest.x-20&&mouse_x<rect_dest.x+rect_dest.w+20&&mouse_y>rect_dest.y-20&&mouse_y<rect_dest.y+rect_dest.h+20)
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
    int virt_x0=Stock[0]->getrect_dest().x;
    int virt_y0=Stock[0]->getrect_dest().y;
    int virt_x1=Stock[1]->getrect_dest().x;
    int virt_y1=Stock[1]->getrect_dest().y;


    for(int i=0;i<20;i++)
    {
        virt_x0 += cos( cap1 * PI / 180.0 )* 5 *sqrt((pow(cos(cap1),2))+(pow(sin(cap1),2)));
        virt_y0 += sin( cap1 * PI / 180.0 )* 5 *sqrt((pow(cos(cap1),2))+(pow(sin(cap1),2)));
        virt_x1 += cos( cap2 * PI / 180.0 )* 5 *sqrt((pow(cos(cap2),2))+(pow(sin(cap2),2)));
        virt_y1 += sin( cap2 * PI / 180.0 )* 5 *sqrt((pow(cos(cap2),2))+(pow(sin(cap2),2)));

        if (((virt_x0 + rect_dest.w < virt_x1)
            || (virt_x0 > virt_x1 + Stock[1]->getrect_dest().w)
            || ((virt_y0 + rect_dest.h < virt_y1)
            || (virt_y0 > virt_y1 + Stock[1]->getrect_dest().h))))
        {
            return false;
        }


       else
        {

        return true;

       }
    }


}
bool Entity::land(std::vector<Entity*> Stock)       //function test if the aircraft is above a landing place
{
    switch (model)
    {
    case 0:
        if(screenwidth/2.1573>rect_dest.x-20&&screenwidth/2.1573<rect_dest.x+rect_dest.w&&screenheight/1.6351>rect_dest.y-20&&screenheight/1.6351<rect_dest.y+rect_dest.h&&new_cap>44&&new_cap<64&&order==0)
        {
            return true;
        }
        if(screenwidth/1.9086>rect_dest.x-20&&screenwidth/1.9086<rect_dest.x+rect_dest.w&&screenheight/1.292>rect_dest.y-20&&screenheight/1.292<rect_dest.y+rect_dest.h&&new_cap>224&&new_cap<244&&order==0)
        {
            return true;
        }
        break;
    case 1:
        if(screenwidth/3.1475>rect_dest.x-20&&screenwidth/3.1475<rect_dest.x+rect_dest.w&&screenheight/4.3512>rect_dest.y-20&&screenheight/4.3512<rect_dest.y+rect_dest.h&&new_cap>44&&new_cap<64&&order==0)
        {
           return true;
        }
        if(screenwidth/2.2776>rect_dest.x-20&&screenwidth/2.2776<rect_dest.x+rect_dest.w&&screenheight/1.8345>rect_dest.y-20&&screenheight/1.8345<rect_dest.y+rect_dest.h&&new_cap>224&&new_cap<244&&order==0)
        {
           return true;
        }
        break;
    case 2:
        if(screenwidth/1.9067>rect_dest.x-20&&screenwidth/1.9067<rect_dest.x+rect_dest.w&&screenheight/1.6351>rect_dest.y-20&&screenheight/1.6351<rect_dest.y+rect_dest.h+20&&order==0)
        {
           return true;
        }
        break;
    }
    return false;


}
bool Entity::crash(std::vector<Entity*> Stock, unsigned int n)      //function control if any Entity is crashing
{
    int touch = 0;

    for(unsigned int i=0; i < Stock.size(); i++)
    {



        if (((rect_dest.x + rect_dest.w < Stock[i]->getrect_dest().x)
            || (rect_dest.x > Stock[i]->getrect_dest().x + Stock[i]->getrect_dest().w)
            || ((rect_dest.y + rect_dest.h < Stock[i]->getrect_dest().y)
            || (rect_dest.y > Stock[i]->getrect_dest().y + Stock[i]->getrect_dest().h))))
        {

        }


       else
        {
            if(i!=n)
            {
                touch++;
            }
            else if(i==n)
            {

            }

        }

        if(touch > 0)
        {
            return true;
        }
        else
        {

        }
    }

    return false;

}
void Entity::set_window_size(int w,int h)
{
    screenwidth=w;
    screenheight=h;
}
void Entity::fly(int cap,char go)       //function move the aircraft a tick further
{
    if (go==2)
    {
        new_cap=cap;
        cap_goto=cap;
    }
    if(cap_goto!=cap&&go==0)
    {
        go=1;
        cap=cap_goto;
    }
    if(go==1)
    {
        cap_goto=cap;
        delta_cap=new_cap-cap;
        if(delta_cap<0)         //keep the direction between 0 and 360
        {
            delta_cap+=360;
        }
        if(delta_cap>180)
        {
            new_cap+=4;
        }
        else
        {
            new_cap-=4;
        }
        if(((delta_cap<4)&&(delta_cap>0))||(delta_cap>356))
        {
            new_cap=cap;
        }

        if(new_cap>360)         //keep the direction between 0 and 360
        {
            new_cap-=360;
        }
        if(new_cap<0)           //keep the direction between 0 and 360
        {
            new_cap+=360;
        }
    }
    else
    {
        new_cap=cap;
    }
    angle = new_cap;
    rect_dest.x += (cos( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap* PI / 180.0 ),2))+(pow(sin(new_cap* PI / 180.0 ),2))));

    rect_dest.y +=( sin( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap* PI / 180.0 ),2))+(pow(sin(new_cap* PI / 180.0 ),2))));


}

void Entity::render(SDL_Renderer* Renderer)         //function draw the Entity on the screen
{

    SDL_RenderCopyEx(Renderer, Bild, &rect_src, &rect_dest, angle, NULL, SDL_FLIP_NONE);    //function draw the aircraft image and turn it in the desired direction

    if(On_click == 1)
    {
        SDL_RenderCopyEx(Renderer, Cercle, &rect_src, &rect_dest, angle, NULL, SDL_FLIP_NONE);  //function draw the circle image on the aircraft if it is selected
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
		SDL_QueryTexture(Bild, NULL, NULL, &rect_dest.w, &rect_dest.h);         //Create texture from surface
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
bool Entity::inside_playfield()
{
    if(rect_dest.x>-49&&rect_dest.x<1929&&rect_dest.y>-49&&rect_dest.y<1074)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Entity::game_point()
{

    switch(order)
    {

        case 0:
            if(rect_dest.x>-49&&rect_dest.x<screenwidth+50&&rect_dest.y>-49&&rect_dest.y<screenheight+50)
            {
                return 100;
            }
            break;

        case 1:
            if(rect_dest.x<0)
            {
                return 10;
            }
            else
            {
                return -10;
            }
            break;

        case 2:
            if(rect_dest.x>screenwidth)
            {
                return 10;
            }
            else
            {
                return -10;
            }
            break;

        case 3:
            if(rect_dest.y<0)
            {
                return 10;
            }
            else
            {
                return -10;
            }
            break;
        case 4:
            if(rect_dest.y>screenheight)
            {
                return 10;
            }
            else
            {
                return -10;
            }
            break;


    }
    return 0;
}
