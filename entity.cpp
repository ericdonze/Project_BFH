#include "entity.h"

Entity::Entity():life(1)
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

bool Entity::IsAlive()
    {
        if(life == 1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

