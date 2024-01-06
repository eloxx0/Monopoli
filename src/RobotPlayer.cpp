#include "../include/RobotPlayer.h"
#include "../include/Casella.h"

RobotPlayer::RobotPlayer(GameTable* p_game){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}

void RobotPlayer::buy_slot(){
    if(position % 7 == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }
    //accede alla casella su cui si trova attualmente il giocatore sulla tabella
    Casella* temp = &(table_p -> table[position]);
    //se la casella è già posseduta, rimuove i soldi del pernottamento
    /* if(temp -> get_giocatore() != 0 && temp -> get_giocatore() != player){ */
    /*     std::cout << "casella già posseduta da altri! Impossibile da comprare." */
    /*         << " Necessario pagare il pernottamento\n"; */
    /*     edit_balance(-(temp -> get_cost())); */
    /* } */
    /* else if(temp -> get_giocatore() == player){ */
    /*     std::cout << "casella già posseduta! Valutare se possibile comprare una casa o un hotel\n"; */
    /*     //richiama il metodo per comprare una casa se possibile */
    /*     buy_house(); */
    /* } */
    /* else if(temp -> get_cost() > balance){ */
    /*     std::cout << "impossibile comprare casella: saldo troppo basso!" */
    /*         << "giocatore " << player << " eliminato\n"; */
    /*     player = 0; */
    /*     balance = 0; */
    /*     table_p = nullptr; */
    /* } */
    /* //probabilità del 25% di acquistare il terreno */
    /* else if(can_buy()){ */
    /*     temp -> set_giocatore(player); */
    /*     std::cout << "terreno acquistato!\n"; */
    /* } */
    /* else{ */
    /*     std::cout << "non succede nulla\n"; */
    /* } */
}

bool can_buy(){
    //se il numero random è minore di 25 posso comprare il terreno/casa/albergo
    std::srand(std::time(0));
    bool probability = (std::rand() % 100) < 25;
    return probability;
}

void RobotPlayer::buy_house(){}

void RobotPlayer::buy_hotel(){}

