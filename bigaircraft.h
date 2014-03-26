#ifndef BIGAIRCRAFT_H
#define BIGAIRCRAFT_H

#include "Aircraft.h"


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
