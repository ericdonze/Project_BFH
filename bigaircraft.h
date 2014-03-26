#ifndef BIGAIRCRAFT_H



// header/funktionen____________________________________________________________________________________________________________
#include "Aircraft.h"
// Variabeln____________________________________________________________________________________________________________________

// Definitionen_________________________________________________________________________________________________________________
#define BIGAIRCRAFT_H

class Bigaircraft : public Aircraft
{
    public:
        Bigaircraft();
        Bigaircraft(int x,int y);
        virtual ~Bigaircraft();

    public:

        int get_test();


    private:

        int test;
};

#endif // BIGAIRCRAFT_H
