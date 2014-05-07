#include "Capp.h"

void Capp::OnLoop() {




    Stock[0]->fly(Cap_next1);
    Stock[1]->fly(Cap_next2);

  /*

    if(Stock[0]->crash(Stock)==1)
        {
        printf("Achtung kollision");
        }



    }*/
    if (Stock[0]->precrash(Stock,Cap_next1, Cap_next2))
        {
            printf("Attention collision inc.");
        }
    if(Stock[0]->crash(Stock)==1)
    {
        Menu=Spielendcard;
    }
}
