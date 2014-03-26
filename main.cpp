#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


#include "Aircraft.h"
#include "Bigaircraft.h"
#include "Smallaircraft.h"



using namespace std;

int main()
{


    std::vector <Entity*> vecteur_entity;





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





    cout << vecteur_entity[0]->IsAlive() << endl;//hei DU
    cout << vecteur_entity[0]->get_coord_x() << endl;
    cout << vecteur_entity[0]->get_test() << endl;



    return 0;
}
