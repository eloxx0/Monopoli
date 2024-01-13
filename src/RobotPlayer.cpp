//ELOISA PAGANI

#include "../include/RobotPlayer.h"

/* Per il RobotPlayer il turno viene gestito in automatico tramite la chiamata della funzione auto_turn(),
* oppure si può chiamare uno ad uno i metodi per comprare separatamente quando il giocatore
* si trova sopra ad una casella*/

RobotPlayer::RobotPlayer(GameTable* p_game){

    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;

    //puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}

//non è necessario controllare che la casella sia di proprietà o acquistabile dal giocatore perchè quando il metodo viene
//richiamato dagli altri metodi il controllo è già stato fatto
bool RobotPlayer::can_buy(Casella* temp){

    //se il terreno è già in possesso di qualcuno oppure se il costo è maggiore del saldo disponibile,
    //non è possibile comprare la casella
    if(temp -> get_cost() > balance) return false;

    //se il numero random da 0 a 100 è minore di 25 posso comprare il terreno/casa/albergo
    std::srand(std::time(0) + rand());

    bool probability = (std::rand() % 100) < 25;

    return probability;

}

void RobotPlayer::auto_turn(){

    advance();
    
    //Se il giocatore arriva sulla partenza oppure su una casella angolare, il turno termina
    if(position % 7 == 0 || position == 0){

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

        //controllo se il giocatore può comprare il terreno utilizzando il metodo player_buyable fornito dalla classe casella
        if(temp -> player_buyable(player) == 1){

            buy_slot();
        }
        //se il player può comprare una casa
        else if(temp -> player_buyable(player) == 2){

            buy_house();
        }
        else if(temp -> player_buyable(player) == 3){

            buy_hotel();
        }
        else{
            std::cout << "non posso acquistare nè pagare\n";
        }
    }

    if(player != 0) print_double("Giocatore " + std::to_string(player) + " ha finito il turno\n");



}


void RobotPlayer::buy_slot(){
    //accede alla casella su cui si trova attualmente il giocatore sulla tabella
    Casella* temp = &(table_p -> table[position]);

    //probabilità del 25% di acquistare il terreno
    if(temp -> player_buyable(player) == 1 && can_buy(temp)){

        temp -> set_propriety(this);
        //setta a 1 la variabile belongings che indica che il terreno è di proprietà di qualcuno
        int cost = temp -> get_cost();
        temp -> set_belongings(1);

        edit_balance(-cost);
        print_double("Il giocatore " + std::to_string(player) + " ha acquistato il terreno in posizione " + conversion_table(position) + "\n");
    }
    else{

        std::cout << "non succede nulla\n";
    }
}

void RobotPlayer::buy_house(){

    Casella* temp = &(table_p -> table[position]);

    //controllo sul balance e sulla probabilità
    if(temp -> player_buyable(player) == 2 && can_buy(temp)){

        int cost = temp -> get_cost();
        //setta a 2 la variabile belongings che indica che sul terreno c'è una casa
        temp -> set_belongings(2);
        edit_balance(-cost);
        print_double("Il giocatore " + std::to_string(player) + " ha acquistato la casa in posizione " + conversion_table(position) + "\n");
    }
    else{

        std::cout << "non succede nulla\n";
    }
}

void RobotPlayer::buy_hotel(){

    Casella* temp = &(table_p -> table[position]);

    if(temp -> player_buyable(player) == 3 && can_buy(temp)){

        int cost = temp -> get_cost();
        temp -> set_belongings(3);


        edit_balance(-cost);

        print_double("Il giocatore " + std::to_string(player) + " ha acquistato l'hotel in posizione " + conversion_table(position) + "\n");
    }
    else{
        std::cout << "non succede nulla\n";
    }
}

