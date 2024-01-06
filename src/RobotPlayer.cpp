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

    //per evitare che la possibilità sia minore del 25% chiamo la funzione buy house prima di can_buy()
    if(temp -> number_player() == player){
        //richiama il metodo per comprare una casa se possibile
        std::cout << "provo a comprare una casa\n";
        buy_house();
        return;
    }

    //probabilità del 25% di acquistare il terreno
    if(can_buy(temp)){

        temp -> set_propriety(this);

        int cost = temp -> get_cost();

        edit_balance(-cost);

        std::cout << "terreno acquistato!\n";
    }
    else{

        std::cout << "non succede nulla\n";
    }
}

bool RobotPlayer::can_buy(Casella* temp){
    //se il terreno è già in possesso di qualcuno oppure se il costo è maggiore del saldo disponibile,
    //non è possibile comprare la casella
    if(temp -> get_cost() > balance) return false;

    if(temp -> number_player() != 0 || temp -> number_player() != player) return false;

    //se il numero random è minore di 25 posso comprare il terreno/casa/albergo
    std::srand(std::time(0));

    bool probability = (std::rand() % 100) < 25;

    return probability;
}

//funzione richiamata dalla funzione buy slot nel caso in cui lo slot è già in possesso del giocatore
void RobotPlayer::buy_house(){

    Casella* temp = &(table_p -> table[position]);

    if(temp -> get_house()){
        buy_hotel();
        return;
    }

    if(can_buy(temp)){

        temp -> set_house(true);

        int cost = temp -> get_cost();

        edit_balance(-cost);

        std::cout << "casa acquistata!\n";
    }
    else{
        std::cout << "non succede nulla\n";
    }
}

void RobotPlayer::buy_hotel(){

    Casella* temp = &(table_p -> table[position]);

    if(temp -> get_house()){
        buy_hotel();
        return;
    }

    if(can_buy(temp)){

        temp -> set_house(false);
        temp -> set_hotel(true);

        int cost = temp -> get_cost();

        edit_balance(-cost);

        std::cout << "hotel acquistato!\n";
    }
    else{
        std::cout << "non succede nulla\n";
    }

}

