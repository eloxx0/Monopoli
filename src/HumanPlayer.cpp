#include "../include/HumanPlayer.h"


HumanPlayer::HumanPlayer(GameTable* p_game){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //setta la variabile puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}

void HumanPlayer::buy_slot(){
    //se il giocatore si trova in una casella angolare non è possibile fare nulla
    if(position % 7 == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }
    //accede alla casella su cui si trova attualmente il giocatore sulla tabella
    Casella* temp = &(table_p -> table[position]);
    //se la casella è già posseduta, rimuove i soldi del pernottamento
    /* if(temp -> get_giocatore() == 0){ */
    /*     temp -> set_giocatore(player); */
    /*     std::cout << "terreno acquistato!\n"; */
    /* } */
    /* else if(temp -> get_giocatore() == player){ */
    /*     std::cout << "casella già posseduta! Valutare se possibile comprare una casa o un hotel\n"; */
    /* } */
    /* else if(temp -> get_cost() > balance){ */
    /*     std::cout << "impossibile comprare casella: saldo troppo basso!" */
    /*         << "giocatore " << player << " eliminato\n"; */
    /*     //azzera tutte le variabili del giocatore */
    /*     player = 0; */
    /*     balance = 0; */
    /*     table_p = nullptr; */
    /*     position = 0; */
    /* } */
    /* else{ */
    /*     std::cout << "casella già posseduta da altri! Impossibile da comprare." */
    /*         << " Necessario pagare il pernottamento\n"; */
    /*     edit_balance(-(temp -> get_cost())); */
    /* } */




}

void HumanPlayer::buy_house(){
}

void HumanPlayer::buy_hotel(){
}

