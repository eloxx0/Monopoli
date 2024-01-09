#ifndef GAMETABLE_H
#define GAMETABLE_H

#include "Casella.h"
#include <random>
#include <chrono>

class GameTable{
    //Salva la posizione (int) del player. Il player viene riconosciuto tramite l'indice della posizione: la posizione del P1 viene salvata in [0], P2 in [1]...
    int player_pos[4]; 
    std::string isPlayer(int);
    std::string isBuilt(int);
    public:
    //Costruttore
    GameTable();
    Casella table[28];
    void printTable();

    void set_player_pos(int i, int pos)     //Da inserire boundary check
    {
        player_pos[i - 1]=pos;
    }
    
};






#endif //GAMETABLE_H


