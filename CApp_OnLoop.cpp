#include "Capp.h"

void Capp::OnLoop() {

   /* for(i=0;i<2;i++)
    {
            if(Stock[i]->get_On_click()==true)
            {
                if(winkel!=Cap_next1)
                {
                    Cap_next1=winkel;
                    Stock[i]->fly(Cap_next1);
                }
                else
                {
                    Stock[i]->fly(Cap_next1);
                }
            }
            else
            {
                Stock[i]->fly(Cap_next1);
            }
    } */
    Stock[0]->fly(winkel);
    Stock[1]->fly(Cap_next2);


    if(Stock[0]->crash(Stock,1)==1)
    {
        Menu=Spielendcard;
    }
}
