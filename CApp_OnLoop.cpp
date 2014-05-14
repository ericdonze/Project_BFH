#include "Capp.h"

void Capp::OnLoop() {

    for(int i=0;i<Stock.size();i++)
    {
            if(Stock[i]->get_On_click()==true)
            {
                if(winkel!=Stock[i]->get_cap_next())
                {
                    Stock[i]->fly(winkel);
                }
                else
                {
                    Stock[i]->fly(Stock[i]->get_cap_next());
                }
            }
            else
            {
                Stock[i]->fly(Stock[i]->get_cap_next());
            }


    if(Stock[i]->crash(Stock, i)==1)
    {
        Menu=Spielendcard;
    }
    }
}
