#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <sstream>

#include "../map/map_gen.h"
#include "m_ia.h"

class simulateur
{
public:
    simulateur();


    void init();//init the simu
    void callPlayers();
    void doPlayerAction();




    void testStream();



    std::stringstream getTurnStream();

    std::string charToTile(char tile);
    my_move moveFromStream(std::stringstream &stream);

private :
    int m_turnId;
    map_gen m_map;

    m_ia P1;
    m_ia P2;

    std::stringstream retP1;
    std::stringstream retP2;


};

#endif // SIMULATEUR_H
