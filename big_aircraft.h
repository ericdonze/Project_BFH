#ifndef BIG_AIRCRAFT_H
#define BIG_AIRCRAFT_H

#include "entity.h"

class Big_aircraft : public entity

{
    public:

        Big_aircraft();
        virtual ~Big_aircraft();



        int get_speed();


    private:

        int speed;
};

#endif // BIG_AIRCRAFT_H
