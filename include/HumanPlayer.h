
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player{
    //i dati membro vengono ereditati direttamente dalla classe di base Player
    
    public:
        //costruttore del giocatore umano. Gli deve essere passato il puntatore al primo
        //elemento della tabella da gioco
        HumanPlayer(GameTable* p);

        //implementazione dei metodi virtuali della classe Player
        void buy_slot();

        void buy_house();

        void buy_hotel();

};

#endif //HUMANPLAYER_H
