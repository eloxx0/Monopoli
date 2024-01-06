#include "../include/HumanPlayer.h"
#include "../include/Casella.h"


HumanPlayer::HumanPlayer(GameTable* p_game){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //setta la variabile puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}

//il caso in cui bisogna pagare il pernottamento viene gestito in automatico dal metodo advance
void HumanPlayer::buy_slot(){
    //se il giocatore si trova in una casella angolare non è possibile fare nulla
    if(position % 7 == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }
    //accede alla casella su cui si trova attualmente il giocatore sulla tabella
    Casella* temp = &(table_p -> table[position]);
    if(temp -> number_player() == 0){
        temp -> set_propriety(this);
        int cost = temp -> get_cost();
        edit_balance(-cost);
        std::cout << "terreno acquistato!\n";
    }

}

void HumanPlayer::buy_house(){
}

void HumanPlayer::buy_hotel(){
}

bool HumanPlayer::can_buy(Casella* temp){

    if(temp -> get_cost() > balance) return false;

    if(temp -> number_player() != 0 || temp -> number_player() != player) return false;

    return true;
}

