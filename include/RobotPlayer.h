#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include "Player.h"

class RobotPlayer : public Player{
    public:

        RobotPlayer(GameTable* p_game);

        void buy_slot() override;

        void buy_house() override;

        void buy_hotel() override;
        
        //metodo che restituisce true con una probabilità del 25% se è possibile comprare un 
        //terreno, una casa o un albergo
        bool can_buy(Casella* temp) override;

};


#endif //ROBOTPLAYER_H
