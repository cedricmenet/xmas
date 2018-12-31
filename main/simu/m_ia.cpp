#include <iostream>

#include "m_ia.h"

using namespace std;

m_ia::m_ia()
{

}

std::stringstream m_ia::play(std::stringstream& data)
{

        int turnType;
        data >> turnType; data.ignore();
        cerr << turnType << endl;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                string tile;
                data >> tile; data.ignore();
                cerr << tile << endl;
            }
        }
        for (int i = 0; i < 2; i++) {
            int numPlayerCards; // the total number of quests for a player (hidden and revealed)
            int playerX;
            int playerY;
            string playerTile;
            data >> numPlayerCards >> playerX >> playerY >> playerTile; data.ignore();
            cerr<<numPlayerCards<< " " <<playerX << " " <<playerY << " " <<playerTile << endl;
        }
        int numItems; // the total number of items available on board and on player tiles
        data >> numItems; data.ignore();
        cerr << "numItems" << numItems << endl;
        for (int i = 0; i < numItems; i++) {
            string itemName;
            int itemX;
            int itemY;
            int itemPlayerId;
            data >> itemName >> itemX >> itemY >> itemPlayerId; data.ignore();
            cerr << itemName<< " " << itemX<< " " << itemY<< " " << itemPlayerId<< endl;
        }
        int numQuests; // the total number of revealed quests for both players
        data >> numQuests; data.ignore();
        cerr << "numQuests" << numQuests << endl;
        for (int i = 0; i < numQuests; i++) {
            string questItemName;
            int questPlayerId;
            data >> questItemName >> questPlayerId; data.ignore();
            cerr << questItemName << " "<< questPlayerId << endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;




        stringstream out;
        out << "PUSH 3 RIGHT" << endl; // PUSH <id> <direction> | MOVE <direction> | PASS


    return out;
}
