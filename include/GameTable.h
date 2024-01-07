#ifndef GAMETABLE_H
#define GAMETABLE_H

#include "Casella.h"
#include <random>
#include <chrono>

class GameTable{

    public:
    //Costruttore
    GameTable();
    Casella table[28];
    void printTable();
    Player* playerID[4];
    
};




#endif //GAMETABLE_H


