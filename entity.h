#ifndef ENTITY_H
#define ENTITY_H


#include <SDL.h>
#include <SDL_image.h>

#include <vector>
#include <iostream>
#include <string>

using namespace std;




     typedef enum       //three type of aircraft
     {
          Small = 0,
          Big = 1 ,
          Heli = 2
     }EEntity;
    typedef enum        //five type of orders
     {
          Landing = 0,
          Left = 1 ,
          Right = 2,
          Up =3,
          Down =4
     }IEntity;

class Entity                    //class for each aircraft
{
    public:
        Entity();                                                                                           //default constructor
        Entity(EEntity aircraft,IEntity Infos,int xposition, int yposition, int cap, SDL_Renderer* render); //overloaded constructor
        virtual ~Entity();
    public:

        SDL_Texture* getBild();                     //function to get the associate image from the Entity
        void setBild(SDL_Texture* text_bild);       //function to set the associate image from the Entity

        SDL_Rect getrect_src();                     //function to get the source SDL_Rect from the Entity
        void setrect_src(SDL_Rect rect_set_src);    //function to set the source SDL_Rect from the Entity

        SDL_Rect getrect_dest();                    //function to get the destination SDL_Rect from the Entity
        void setrect_dest(SDL_Rect rect_set_dest);  //function to set the destination SDL_Rect from the Entity

        int get_x_position();                           //function returns the x position of the aircraft
        int get_y_position();                           //function returns the y position of the aircraft
        int get_width();                                //function returns the width of the aircraft
        int get_height();                               //function returns the height of the aircraft
        double get_cap_next();                          //function returns the next direction of the aircraft
        void set_infos(std::string* p);                 //function set a new order in the string from the Entity
        bool inside_entity(int mouse_x, int mouse_y);   //function test if the mouse is above an Entity
        bool inside_playfield();                        //function test if the Entity is still on the playground
        int game_point();                               //function manage the game points
        void set_window_size(int w,int h);


        bool get_On_click();                                            //function returns if the aircraft is selected or not
        void set_On_click(bool click);                                  //function set the new state of On_click
        bool precrash(std::vector<Entity*> Stock, int cap1, int cap2);  //function looks if it will have a collision
        void fly(int cap,char go);                                      //function move the aircraft a tick further
        bool crash(std::vector<Entity*> Stock,unsigned int n);          //function control if any Entity is crashing
        bool land(std::vector<Entity*> Stock);                          //function test if the aircraft is above a landing place
        void render(SDL_Renderer* Renderer);                            //function draw the Entity on the screen
        void loadbild(SDL_Renderer* Renderer, const char *image);       //function to load the image of the aircraft



    private:

        SDL_Texture* Bild = NULL;               //texture who contain the image of the aircraft
        SDL_Texture* Cercle = NULL;             //texture who contain the image of the circle when an aircraft is selected
        SDL_Surface* Loading_Surf_Entity = NULL;//Surface to load the image on the texture
        SDL_Rect rect_dest;                     //SDL_Rect from destination (x,y,width,height)
        SDL_Rect rect_src;                      //SDL_Rect from source (x,y,width,height)
        std::string Info_Flugzeug;              //string who contain the text for the informations of the aircraft
        int new_Posx;                           //new X position
        int new_Posy;                           //new Y position
        int new_cap;                            //new direction
        int delta_cap;                          //difference between two direction
        int cap_goto;                           //direction who it should go
        int screenwidth,screenheight;
        double angle;                           //angle of the aircraft between 0 and 360 degrees
        bool On_click;                          //boolean variable to know if the aircraft is selected or not
        IEntity order;                          //type from typdef of the order
        EEntity model;                          //type from typdef from the model of aircraft

};

#endif // ENTITY_H
