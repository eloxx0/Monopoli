#include "../include/HumanPlayer.h"


HumanPlayer::HumanPlayer(GameTable* p){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p;

}

void HumanPlayer::buy_slot(){
    //se non si trova in una casella angolare
    if(position % 7 == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }


}

void HumanPlayer::buy_house(){
}

void HumanPlayer::buy_hotel(){
}

