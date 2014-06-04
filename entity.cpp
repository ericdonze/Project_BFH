#include "entity.h"
#include <string.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "math.h"       //library with mathematics tools
#include "capp.h"

#define PI 3.14159265

Entity::Entity()    //default constructor
{
    new_Posx = 0;
    new_Posy = 0;
    new_cap = 4;
    angle = 0;
    On_click = 0;

    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 200;
    rect_src.h = 200;

    rect_dest.x = 100;      //start x position
    rect_dest.y = 100;      //start y position
    rect_dest.w = 20;       //image width
    rect_dest.h = 20;       //image height
}

Entity::Entity(EEntity aircraft,IEntity Infos, int xposition, int yposition, int cap, SDL_Renderer* render) //overloaded constructor
{
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

    rect_dest.x = xposition;    //start x position
    rect_dest.y = yposition;    //start y position

    order = Infos;              //set the order
    model = aircraft;           //set the type of aircraft
    switch(Infos)               //set the right order in the string Info_Flugzeug
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
    switch(aircraft)            //adapt the image size for each aircraft
    {
        case 0:
        rect_dest.w = 30;
        rect_dest.h = 30;
        break;

        case 1:
        rect_dest.w = 40;
        rect_dest.h = 40;
        break;

        case 2:
        rect_dest.w = 25;
        rect_dest.h = 25;
        break;

        default:
        rect_dest.w = 40;
        rect_dest.h = 40;
        break;

    }


    switch(aircraft)        //load the right image of the aircraft
    {
        case 0:
        Loading_Surf_Entity = IMG_Load("Pitts_23-23.png");

        break;

        case 1:
        Loading_Surf_Entity = IMG_Load("A380_30-30.png");

        break;

        case 2:
        Loading_Surf_Entity = IMG_Load("hughes_25-25.png");

        break;

        default:
        Loading_Surf_Entity = IMG_Load("A380_30-30.png");

        break;

    }




    if( Loading_Surf_Entity == NULL )   //test if image is loaded on the surface
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Entity.png", IMG_GetError() );   //error message when the image is not loaded
	}
	else
	{
		SDL_QueryTexture(Bild, NULL, NULL, &rect_dest.w, &rect_dest.h);

        Bild = SDL_CreateTextureFromSurface(render, Loading_Surf_Entity);           //Create texture from surface / transfer the image
		if( Bild == NULL )  // test if the texture is loaded on the texture
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Entity.png", SDL_GetError() );    //error message when the image is not loaded on the texture
		}


		SDL_FreeSurface(Loading_Surf_Entity);   //clean the temporary load surface
	}





	Loading_Surf_Entity = IMG_Load("cercle_rouge.png"); //load the circle image on the surface

	if( Loading_Surf_Entity == NULL )                   //test if the circle is on the surface
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Cercle.png", IMG_GetError() );   //error message when the circle is not loaded on surface
	}
	else
	{
		SDL_QueryTexture(Cercle, NULL, NULL, &rect_dest.w, &rect_dest.h);
                                                                                                //Create texture from surface
        Cercle = SDL_CreateTextureFromSurface(render, Loading_Surf_Entity);
		if( Cercle == NULL )        ////test if the circle is on the texture
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", "Cercle.png", SDL_GetError() );    //error message when the circle is not loaded on texture
		}


		SDL_FreeSurface(Loading_Surf_Entity);   //clean the temporary load surface
	}

}

Entity::~Entity()   //destructor
{

}

SDL_Texture* Entity::getBild()                  //function to get the associate image from the Entity
{
    return Bild;
}

void Entity::setBild(SDL_Texture* text_bild)    //function to set the associate image from the Entity
{

    Bild = text_bild;
}

SDL_Rect Entity::getrect_src()                  //function to get the source SDL_Rect from the Entity
{
    return rect_src;
}

void Entity::setrect_src(SDL_Rect rect_set_src) //function to set the source SDL_Rect from the Entity
{

    rect_src = rect_set_src;
}

SDL_Rect Entity::getrect_dest()                 //function to get the destination SDL_Rect from the Entity
{
    return rect_dest;
}

void Entity::setrect_dest(SDL_Rect rect_set_dest)//function to set the destination SDL_Rect from the Entity
{
    rect_dest = rect_set_dest;
}
int Entity::get_x_position()                    //function returns the x position of the aircraft
{
    return rect_dest.x;
}
int Entity::get_y_position()                    //function returns the y position of the aircraft
{
    return rect_dest.y;
}
int Entity::get_width()                         //function returns the width of the aircraft
{
    return rect_dest.w;
}
int Entity::get_height()                        //function returns the height of the aircraft
{
    return rect_dest.h;
}
void Entity::set_infos(std::string* p)          //function set a new order in the string from the Entity
{
    *p=Info_Flugzeug;

}
double Entity::get_cap_next()                   //function returns the next direction of the aircraft
{
    return angle;
}
bool Entity::inside_entity(int mouse_x, int mouse_y)//function test if the mouse is above an Entity
{
    if(mouse_x>rect_dest.x-20&&mouse_x<rect_dest.x+rect_dest.w+20&&mouse_y>rect_dest.y-20&&mouse_y<rect_dest.y+rect_dest.h+20)
    {
        return true;        //return true if the mouse is inside the Entity
    }
    else
    {
        return false;       //return false if the mouse is abroad the Entity
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
bool Entity::land(std::vector<Entity*> Stock)   //function test if the aircraft is above a landing place
{
    switch (model)
    {
    case 0:
        if(890>rect_dest.x-20&&890<rect_dest.x+rect_dest.w&&644>rect_dest.y-20&&644<rect_dest.y+rect_dest.h&&new_cap>44&&new_cap<64&&order==0)
        {
            return true;
        }
        if(1006>rect_dest.x-20&&1006<rect_dest.x+rect_dest.w&&815>rect_dest.y-20&&815<rect_dest.y+rect_dest.h&&new_cap>224&&new_cap<244&&order==0)
        {
            return true;
        }
        break;
    case 1:
        if(610>rect_dest.x-20&&610<rect_dest.x+rect_dest.w&&242>rect_dest.y-20&&242<rect_dest.y+rect_dest.h&&new_cap>44&&new_cap<64&&order==0)
        {
           return true;
        }
        if(843>rect_dest.x-20&&843<rect_dest.x+rect_dest.w&&574>rect_dest.y-20&&574<rect_dest.y+rect_dest.h&&new_cap>224&&new_cap<244&&order==0)
        {
           return true;
        }
        break;
    case 2:
        if(1007>rect_dest.x-20&&1007<rect_dest.x+rect_dest.w&&644>rect_dest.y-20&&644<rect_dest.y+rect_dest.h+20&&order==0)
        {
           return true;
        }
        break;
    }
    return false;


}
bool Entity::crash(std::vector<Entity*> Stock, unsigned int n)  //function control if any Entity is crashing
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
void Entity::fly(int cap,char go)   //function move the aircraft a tick further
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
        if(delta_cap<0)
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

        if(new_cap>360)
        {
            new_cap-=360;
        }
        if(new_cap<0)
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
    if ((rect_dest.x <-50) || (rect_dest.x>1930))
    {
        rect_dest.x -= (cos( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap* PI / 180.0 ),2))+(pow(sin(new_cap* PI / 180.0 ),2))));
    }
    rect_dest.y +=( sin( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap* PI / 180.0 ),2))+(pow(sin(new_cap* PI / 180.0 ),2))));
    if ((rect_dest.y <-50) || (rect_dest.y>1075))
    {
        rect_dest.y -= (sin( new_cap * PI / 180.0 )* 5 *sqrt((pow(cos(new_cap* PI / 180.0 ),2))+(pow(sin(new_cap* PI / 180.0 ),2))));
    }

}

void Entity::render(SDL_Renderer* Renderer)
{

    SDL_RenderCopyEx(Renderer, Bild, &rect_src, &rect_dest, angle, NULL, SDL_FLIP_NONE);

    if(On_click == 1)
    {
        SDL_RenderCopyEx(Renderer, Cercle, &rect_src, &rect_dest, angle, NULL, SDL_FLIP_NONE);
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
            if(rect_dest.x>-49&&rect_dest.x<1929&&rect_dest.y>-49&&rect_dest.y<1074)
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
            if(rect_dest.x>1900)
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
            if(rect_dest.y>1035)
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
