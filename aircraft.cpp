#include "aircraft.h"

Aircraft::Aircraft()
{

}

Aircraft::Aircraft(int x, int y)
{
    this->set_coord_x(x);
    this->set_coord_y(y);

}

Aircraft::~Aircraft()
{
    //dtor
}


int Aircraft::get_coord_x()
    {
        return coord_x;
    }

int Aircraft::get_coord_y()
    {
        return coord_y;
    }

void Aircraft::set_coord_x(int new_x)
    {
        coord_x = new_x;
    }

void Aircraft::set_coord_y(int new_y)
    {
        coord_y = new_y;
    }

bool Aircraft::crash(int x_other, int y_other ,int n_coord)
{
    if(n_coord == 1)
    {

        if (coord_x < (x_other+10) && coord_y > (y_other-10) &&coord_x > (x_other-10) && coord_y < (y_other+10))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }
}
