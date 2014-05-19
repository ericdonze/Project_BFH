#ifndef ENTITY_H
#define ENTITY_H


#include <SDL.h>
#include <SDL_image.h>

#include <vector>
#include <iostream>
#include <string>
using namespace std;




     typedef enum
     {
          Small = 0,
          Big = 1 ,
          Heli = 2
     }EEntity;
    typedef enum
     {
          Landing = 0,
          Left = 1 ,
          Right = 2,
          Up =3,
          Down =4
     }IEntity;

class Entity
{
    public:
        Entity();
        Entity(EEntity aircraft,IEntity Infos,int xposition, int yposition, int cap, SDL_Renderer* moi);
        virtual ~Entity();
    public:

        SDL_Texture* getBild();
        void setBild(SDL_Texture* truc);

        SDL_Rect getsrc_test();
        void setsrc_test(SDL_Rect truc);

        SDL_Rect getdest_test();
        void setdest_test(SDL_Rect truc);

        int get_x_position();
        int get_y_position();
        int get_width();
        int get_height();
        double get_cap_next();
        void set_infos(std::string* p);
        char inside_entity(int mouse_x, int mouse_y);
        bool inside_playfield();



        bool get_On_click();
        void set_On_click(bool click);
        bool precrash(std::vector<Entity*> Stock, int cap1, int cap2);
        void fly(int cap,char go);
        bool crash(std::vector<Entity*> Stock,int n);
        bool land(std::vector<Entity*> Stock);
        void render(SDL_Renderer* Renderer);
        void loadbild(SDL_Renderer* Renderer, const char *image);



    private:

        SDL_Texture* Bild = NULL;
        SDL_Texture* Cercle = NULL;
        SDL_Surface* Loading_Surf_Entity = NULL;
        SDL_Rect dest_test;
        SDL_Rect src_test;
        std::string Info_Flugzeug;
        int new_Posx;
        int new_Posy;
        int new_cap;
        int delta_cap;
        int cap_goto;
        double angle;
        bool On_click;
};

#endif // ENTITY_H
