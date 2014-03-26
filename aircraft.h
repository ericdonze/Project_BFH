#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"


class Aircraft : public Entity
{
    public:
        Aircraft();
        Aircraft(int x, int y);

        virtual ~Aircraft();

    public:

        int get_coord_x();
        int get_coord_y();
        void set_coord_x(int new_x);
        void set_coord_y(int new_y);
        bool crash(int x_other, int y_other ,int n_coord);

        //virtual int get_test() = 0;
        //virtual int get_test2() = 0;




    private:

        int coord_x;
        int coord_y;
        int n_coord;

};

#endif // AIRCRAFT_H
