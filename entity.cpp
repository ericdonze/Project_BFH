
// header/funktionen____________________________________________________________________________________________________________
#include "entity.h"
// Variabeln____________________________________________________________________________________________________________________

// Definitionen_________________________________________________________________________________________________________________
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
