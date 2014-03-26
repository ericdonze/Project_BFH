#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// header/funktionen____________________________________________________________________________________________________________
#include "Aircraft.h"
#include "Bigaircraft.h"
#include "Smallaircraft.h"
// Variabeln____________________________________________________________________________________________________________________
unsigned char ende=1;
unsigned char Menu=0;
// Definitionen_________________________________________________________________________________________________________________
#define Hauptmenu 0
#define Spielablauf 1
#define Spielendcard 2


using namespace std;

int main()
{


    std::vector <Entity*> vecteur_entity;

    while(ende)
    {
        switch(Menu)
        {
            case Hauptmenu:
                //Input;
                //Output;
            break;
            case Spielablauf:
                //Input;
                //Berechnung;
                //Output;
            break;

            case Spielendcard:
                //Input;
                //Output;
            break;
        }

    }



    Bigaircraft *airbus(0);
    airbus = new Bigaircraft;

    //Smallaircraft *pilatus(0);
    //pilatus = new Smallaircraft;







    Bigaircraft adrian(123,145);
    //Smallaircraft eric(124,200);




    *airbus = adrian;
    //*pilatus = eric;





    vecteur_entity.push_back(airbus);
    //vecteur_entity.push_back(pilatus);





    cout << vecteur_entity[0]->IsAlive() << endl;
    cout << vecteur_entity[0]->get_coord_x() << endl;
    cout << vecteur_entity[0]->get_test() << endl;



    return 0;
}
