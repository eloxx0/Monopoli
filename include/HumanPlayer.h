
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player{
    //i dati membro vengono ereditati direttamente dalla classe di base Player
    
    public:
        //costruttore del giocatore umano. Gli deve essere passato il puntatore al primo
        //elemento della tabella da gioco
        HumanPlayer(GameTable* p_game);

        //implementazione dei metodi virtuali della classe Player
        void buy_slot() override;

        void buy_house() override;

        void buy_hotel() override;

        //metodo che restituisce true se il giocatore può comprare la casella
        //passata come parametro, false altrimenti
        bool can_buy(Casella* temp) override;

};

#endif //HUMANPLAYER_H
