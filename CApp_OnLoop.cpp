#include "Capp.h"

void Capp::OnLoop() {

    for(i=0;i<Stock.size();i++)
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
    }

    if(Stock[0]->crash(Stock)==1)
    {
        Menu=Spielendcard;
    }
}
