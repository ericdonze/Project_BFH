#include "Capp.h"

void Capp::OnLoop() {




    Stock[0]->fly(Cap_next1);
    Stock[1]->fly(Cap_next2);

    printf("crash:%d \n", Stock[0]->crash(Stock));
    if(Stock[0]->crash(Stock)==1)
    {
        Menu=Spielendcard;
    }
}
