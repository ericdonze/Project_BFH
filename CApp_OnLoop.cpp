#include "Capp.h"

void Capp::OnLoop() {

    for(i=0;i<Stock.size();i++)
    {
        if(Stock[i]->get_On_click()==true)
        {
            if(winkel!=Stock[i]->get_cap_next())
            {
                Stock[i]->fly(winkel,1);
            }
            else
            {
                Stock[i]->fly(Stock[i]->get_cap_next(),0);
            }
            Stock[i]->set_infos(&data);
        }
        else
        {
            z++;
            Stock[i]->fly(Stock[i]->get_cap_next(),0);
        }

        if(Stock[i]->land(Stock)==1)
        {
            printf("landing succeeded");
        }

        if(Stock[i]->crash(Stock,i)==1)
        {
            Menu=Spielendcard;
        }
    }
    if(z==Stock.size())
    {
        data="";
    }
    z=0;
}
