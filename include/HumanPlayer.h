
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player{
    //i dati membro vengono ereditati direttamente dalla classe di base Player
    
    public:
        //costruttore del giocatore umano. Gli deve essere passato il puntatore al tabellone di gioco
        HumanPlayer(GameTable* p_game);

        //implementazione dei metodi virtuali della classe Player
        void buy_slot() override;

        void buy_house() override;

        void buy_hotel() override;

        //funzione che compra in automatico il possedimento(terreno, casa o hotel) su cui si trova il giocatore se possibile
        /* void buy(); */

};

#endif //HUMANPLAYER_H
