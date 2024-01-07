#include "../include/RobotPlayer.h"
#include "../include/Casella.h"

/* Per il RobotPlayer il turno viene gestito in automatico tramite la chiamata della funzione auto_turn()
 * quando il giocatore si trova sopra ad una casella*/

RobotPlayer::RobotPlayer(GameTable* p_game){

    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;

    //puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}


//nel can_buy viene gestito in automatico il caso in cui è necessario pagare il pernottamento ad 
//un altro giocatore, poichè le variabili da controllare sono sempre le stesse
bool RobotPlayer::can_buy(Casella* temp){

    //se il terreno è già in possesso di qualcuno oppure se il costo è maggiore del saldo disponibile,
    //non è possibile comprare la casella
    if(temp -> get_cost() > balance) return false;

    //il metodo pay_player ritorna true se è stato pagato il pernottamento ad un altro giocatore,
    //che vuol dire che la casella non è acquistabile. 
    if(temp -> number_player() != player && temp -> number_player() != 0) return false;
    
    //se il numero random è minore di 25 posso comprare il terreno/casa/albergo
    std::srand(std::time(0));

    bool probability = (std::rand() % 100) < 25;

    return probability;
}

void RobotPlayer::auto_turn(){

    advance();
    
    //Se il giocatore arriva sulla partenza oppure su una casella angolare, il turno termina
    if(position % 7 == 0 && position == 0){

        std::cout << "non posso fare nulla!\n";
        return;
    }

    //tenta di pagare il giocatore se la casella è già posseduta da qualcuno:
    //la variabile viene settata a true se il pagamento è andato a buon fine o il giocatore
    //è stato eliminato. In questo caso il turno termina
    bool esito_pagamento = pay_player();

    //se non è stato pagato il pernottamento, o se il giocatore è stato eliminato, viene chiamata la
    //funzione buy slot();
    if(!esito_pagamento){
        //puntatore alla casella in cui si trova il giocatore
        Casella* temp = &(table_p -> table[position]);
        //se la casella non è di proprietà di nessuno
        if(temp -> number_player() == 0){

            buy_slot();
        }
        else if(temp -> number_player() == player){

            buy_house();
        }
        else if(temp -> get_house()){

            buy_hotel();
        }
    }

}


void RobotPlayer::buy_slot(){
    
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


//funzione richiamata dalla funzione buy slot nel caso in cui lo slot è già in possesso del giocatore
void RobotPlayer::buy_house(){

    Casella* temp = &(table_p -> table[position]);

    if(temp -> get_house()){
        std::cout << "Provo a comprare un hotel\n";
        buy_hotel();
        return;
    }

    //controllo sul balance e sulla probabilità
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

    if(temp -> get_hotel()){

        std::cout << "hotel già acquistato! Non posso fare nulla\n";
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

