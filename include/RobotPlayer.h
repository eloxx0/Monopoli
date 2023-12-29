#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include "Player.h"

class RobotPlayer : public Player{
    public:

        RobotPlayer();

        void buy_slot();

        void buy_house();

        void buy_hotel();

};

#endif //ROBOTPLAYER_H
