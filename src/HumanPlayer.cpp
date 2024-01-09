#include "../include/HumanPlayer.h"

/* Per gestire il turno del giocatore umano è possibile chiamare la funzione buy() che compra in automatico il 
* possedimento o la casa o l'albergo se possibile, oppure utilizzare separatamente le funzioni di acquisto 
* in base al volere del giocatore*/


HumanPlayer::HumanPlayer(GameTable* p_game){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //setta la variabile puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;
    /* table_p -> set_player_pos(player, 0); */

}

void HumanPlayer::buy(){

    Casella* temp = &(table_p -> table[position]);
    
    //se il giocatore si trova in una casella angolare non è possibile fare nulla
    if(position % 7 == 0 && position == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }
    if(temp -> player_buyable(player) == 1){
        buy_slot();
    }
    else if(temp -> player_buyable(player) == 2){
        buy_house();
    }
    else if(temp -> player_buyable(player) == 3){
        buy_hotel();
    }
    else{
        std::cout << "impossibile comprare\n";
    }
}

void HumanPlayer::buy_slot(){
    Casella* temp = &(table_p -> table[position]);

    if(temp -> player_buyable(player) == 1){

        int cost = temp -> get_cost();
        temp -> set_propriety(this);
        temp -> set_belongings(1);

        edit_balance(-cost);
        std::cout << "terreno acquistato!\n";
    }
    else{

        std::cout << "non succede nulla\n";
    }
}

void HumanPlayer::buy_house(){
    Casella* temp = &(table_p -> table[position]);

    if(temp -> player_buyable(player) == 2){

        int cost = temp -> get_cost();
        temp -> set_belongings(2);
        edit_balance(-cost);
        std::cout << "casa acquistata!\n";
    }
    else{

        std::cout << "non succede nulla\n";
    }

}

void HumanPlayer::buy_hotel(){
    Casella* temp = &(table_p -> table[position]);

    if(temp -> player_buyable(player) == 3){

        int cost = temp -> get_cost();
        temp -> set_belongings(3);
        edit_balance(-cost);
        std::cout << "hotel acquistato!\n";
    }
    else{

        std::cout << "non succede nulla\n";
    }

}

