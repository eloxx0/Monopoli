#include "../include/HumanPlayer.h"

/* Per gestire il turno del giocatore umano è necessario chiamare le funzioni apposite dopo aver verificato cosa è possibile comprare*/


HumanPlayer::HumanPlayer(GameTable* p_game){
    //numero identificativo del player definito in base al numero di giocatori attuali
    //tutti gli altri dati membro sono inizializzati al valore di base
    player = ++num_player;
    //setta la variabile puntatore alla tabella di gioco, necessario per accedere alle caselle
    table_p = p_game;

}

void HumanPlayer::buy_slot(){
    Casella* temp = &(table_p -> table[position]);

    //basta il controllo sulla casella angolare nel buy_slot() poichè gli altri metodi possono essere chiamati solo 
    //se il terreno è già stato comprato
    if(position % 7 == 0 || position == 0){
        std::cout << "non posso fare nulla!\n";
        return;
    }

    if(temp -> player_buyable(player) == 1){

        int cost = temp -> get_cost();
        temp -> set_propriety(this);
        temp -> set_belongings(1);

        edit_balance(-cost);
        print_double("Il giocatore " + std::to_string(player) + " ha acquistato il terreno in posizione " + conversion_table(position) + "\n");
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
        print_double("Il giocatore " + std::to_string(player) + " ha acquistato la casa in posizione " + conversion_table(position) + "\n");
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
        print_double("Il giocatore " + std::to_string(player) + " ha acquistato l'hotel in posizione " + conversion_table(position) + "\n");
    }
    else{

        std::cout << "non succede nulla\n";
    }

}

