#include <iostream>


#include "simulateur.h"


using namespace std;

simulateur::simulateur()
{




/**
 * Help the Christmas elves fetch presents in a magical labyrinth!
 **/


    // game loop



}

void simulateur::init()
{
    m_map.map_gen_rand();
}

void simulateur::callPlayers()
{

    stringstream state = getTurnStream();

    retP1 = P1.play(state);
    state = getTurnStream();

    retP2 = P2.play(state);


    moveFromStream(retP1);

}

void simulateur::doPlayerAction()
{

}

stringstream simulateur::getTurnStream()
{

    stringstream stream;
    stream << m_turnId%2 << endl; //0 push 1 move

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            string tile = charToTile(m_map.getBoard().board[j+i*7]);
            stream << tile << endl;
        }
    }


    stream << static_cast<int>(m_map.getBoard().objs_p1_s) << endl;
    stream << static_cast<int>(m_map.getBoard().p1.x) << endl;
    stream << static_cast<int>(m_map.getBoard().p1.y) << endl;
    stream << charToTile(m_map.getBoard().p1_tile) << endl;

    stream << static_cast<int>(m_map.getBoard().objs_p2_s) << endl;
    stream << static_cast<int>(m_map.getBoard().p2.x) << endl;
    stream << static_cast<int>(m_map.getBoard().p2.y) << endl;
    stream << charToTile(m_map.getBoard().p2_tile) << endl;

    //all items

    stream << static_cast<int>(m_map.getBoard().objs_p1_s + m_map.getBoard().objs_p2_s) << endl;;

    for(int i = 0; i < m_map.getBoard().objs_p1_s;i++)
    {
        stream << board::univ_obj[m_map.getBoard().objs_p1[i].type] << endl;
        stream << static_cast<int>(m_map.getBoard().objs_p1[i].pos.x) << endl;
        stream << static_cast<int>(m_map.getBoard().objs_p1[i].pos.y) << endl;
        stream << 0 << endl;
    }

    for(int i = 0; i < m_map.getBoard().objs_p2_s;i++)
    {
        stream << board::univ_obj[m_map.getBoard().objs_p2[i].type] << endl;
        stream << static_cast<int>(m_map.getBoard().objs_p2[i].pos.x) << endl;
        stream << static_cast<int>(m_map.getBoard().objs_p2[i].pos.y) << endl;
        stream << 1 << endl;
    }


    stream << static_cast<int>(m_map.getBoard().objs_p1_active_length + m_map.getBoard().objs_p2_active_length)  << endl;

    for(int i = 0; i < m_map.getBoard().objs_p1_active_length;i++)
    {
        stream << board::univ_obj[m_map.getBoard().objs_p1_active[i]] << endl;
        stream << 0 << endl;
    }
    for(int i = 0; i < m_map.getBoard().objs_p2_active_length;i++)
    {
        stream << board::univ_obj[m_map.getBoard().objs_p2_active[i]] << endl;
        stream << 1 << endl;
    }


    return stream;




    /*int turnType;
    cin >> turnType; cin.ignore();
    cerr << turnType << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            string tile;
            cin >> tile; cin.ignore();
            cerr << tile << endl;
        }
    }
    for (int i = 0; i < 2; i++) {
        int numPlayerCards; // the total number of quests for a player (hidden and revealed)
        int playerX;
        int playerY;
        string playerTile;
        cin >> numPlayerCards >> playerX >> playerY >> playerTile; cin.ignore();
        cerr<<numPlayerCards<< " " <<playerX << " " <<playerY << " " <<playerTile << endl;
    }
    int numItems; // the total number of items available on board and on player tiles
    cin >> numItems; cin.ignore();
    cerr << numItems << endl;
    for (int i = 0; i < numItems; i++) {
        string itemName;
        int itemX;
        int itemY;
        int itemPlayerId;
        cin >> itemName >> itemX >> itemY >> itemPlayerId; cin.ignore();
        cerr << itemName<< " " << itemX<< " " << itemY<< " " << itemPlayerId<< endl;
    }
    int numQuests; // the total number of revealed quests for both players
    cin >> numQuests; cin.ignore();
    cerr << numQuests << endl;
    for (int i = 0; i < numQuests; i++) {
        string questItemName;
        int questPlayerId;
        cin >> questItemName >> questPlayerId; cin.ignore();
        cerr << questItemName << " "<< questPlayerId << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "PUSH 3 RIGHT" << endl; // PUSH <id> <direction> | MOVE <direction> | PASS
*/
}

string simulateur::charToTile(char tile)
{
    string toRet; //  en haut, à droite, en bas, à gauche
    for(int i = 3; i >= 0;i--)
    {
        if((tile >> i) & 0x01)
            toRet += '1';
        else
            toRet+='0';
    }

    return toRet;
}

my_move simulateur::moveFromStream(stringstream& stream)
{
    string key;
    int id;
    string direction;

    stream >> key >> id >> direction;

    cerr << key <<" " <<  id <<" " << direction;


    if(direction == "UP")
        return {static_cast<char>(id),0,1};
    else if(direction == "DOWN")
        return {static_cast<char>(id),0,0};
    else if(direction == "LEFT")
        return {static_cast<char>(id),1,1};
    else if(direction == "RIGHT")
        return {static_cast<char>(id),1,0};

    return {0,0,0};

}
