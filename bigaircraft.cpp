
// header/funktionen____________________________________________________________________________________________________________
#include "bigaircraft.h"

// Variabeln____________________________________________________________________________________________________________________

// Definitionen_________________________________________________________________________________________________________________

Bigaircraft::Bigaircraft() : test(5)
{

}

Bigaircraft::Bigaircraft(int x, int y) : test(5)
{
    this->set_coord_x(x);
    this->set_coord_y(y);
}

Bigaircraft::~Bigaircraft()
{
    //dtor
}

int Bigaircraft::get_test()
{

    return test;

}
