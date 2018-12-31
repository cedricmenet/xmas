#include <iostream>


#include "simulateur.h"

int main (){


    simulateur s;


    s.init();
    s.callPlayers();
    s.doPlayerAction();


    return 0;
}
