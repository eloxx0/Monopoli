#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"
#include <fstream> //per il file log per array di char
#include <bits/stdc++.h>
#include <algorithm>

//array che mantiene l'ordine dei giocatori: i numeri scritti all'interno rappresentano
//l'identificativo dei giocatori nell'ordine in cui devono procedere a giocare
std::vector<int> ordine_giocatori;

//variabile che indica i turni giocati. Il numero di turni massimi è 100: dopo di questo, se il gioco non è ancora terminato,
//viene dichiarato un vincitore in base al bilancio
int turns = 0;

void player_order(int disordered_results[4]){
    int ordered_results[4] = {disordered_results[0], disordered_results[1], disordered_results[2], disordered_results[3]};
    std::sort(ordered_results, ordered_results + 4, std::greater<int>());
    for(int i = 0; i < 4; i++){
        if(ordered_results[i] == disordered_results[0]) ordine_giocatori.push_back(1);
        else if(ordered_results[i] == disordered_results[1]) ordine_giocatori.push_back(2);
        else if(ordered_results[i] == disordered_results[2]) ordine_giocatori.push_back(3);
        else if(ordered_results[i] == disordered_results[3]) ordine_giocatori.push_back(4);
    }

}

std::vector<int> winner(Player* a, Player* b, Player* c, Player* d){
    std::vector<int> winners;
    int a_bal = a -> show_balance();
    int b_bal = b -> show_balance();
    int c_bal = c -> show_balance();
    int d_bal = d -> show_balance();
    winners.push_back(a_bal);
    winners.push_back(b_bal);
    winners.push_back(c_bal);
    winners.push_back(d_bal);
    std::sort(winners.begin(), winners.end(), std::greater<int>());

    for(int i = 3; i >= 0; i--){
        if(winners[i] == 0) winners.pop_back();
    }
    int size = winners.size();
    for(int i = size - 1 ; i>0; i--){
        if(winners[i] < winners[i - 1]) winners.pop_back();
        else if(i >= 2 && winners[i] == winners[i -1] && winners[i] < winners[i-2]){
            winners.pop_back();
            winners.pop_back();
            i = i - 1;
        }
    }
    std::vector<int> number_winners;
    if(std::binary_search(winners.begin(), winners.end(), a_bal)){
        number_winners.push_back(1);
    }
    if(std::binary_search(winners.begin(), winners.end(), b_bal)){
        number_winners.push_back(2);
    }
    if(std::binary_search(winners.begin(), winners.end(), c_bal)){
        number_winners.push_back(3);
    }
    if(std::binary_search(winners.begin(), winners.end(), d_bal)){
        number_winners.push_back(4);
    }
    return number_winners;

}

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cerr << "Necessario inserire \"bin/main computer\" o \"bin/main human\" in base alla modalità di gioco desiderata. Riprovare\n";
        return 0;
    }
    std::string command(argv[1]);

    if(command.compare("computer") != 0 && command.compare("human") != 0){
        std::cerr << " Comandi sconosciuti: inserire \"computer\" o \"human\" in base alla modalità di gioco\n";
        return 0;
    }

    GameTable game;

    if(command.compare("computer") == 0){

        RobotPlayer a(&game);
        RobotPlayer b(&game);
        RobotPlayer c(&game);
        RobotPlayer d(&game);

        int a_val = throw_dice();
        int b_val = throw_dice();
        int c_val = throw_dice();
        int d_val = throw_dice();
        //faccio ritirare i dadi finchè non sono diversi tutti i valori
        int results[4] = {a_val, b_val, c_val, d_val};
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                if(results[i] == results[j]) results[j] = throw_dice();
            }
        }
        //copio i nuovi valori nelle variabili
        a_val = results[0];
        b_val = results[1];
        c_val = results[2];
        d_val = results[3];

        std::cout << "il giocatore 1 tira il dado ed esce " << a_val << "\n";
        std::cout << "il giocatore 2 tira il dado ed esce " << b_val << "\n";
        std::cout << "il giocatore 3 tira il dado ed esce " << c_val << "\n";
        std::cout << "il giocatore 4 tira il dado ed esce " << d_val << "\n";

        player_order(results);

        std::cout << "ordine dei giocatori: ";
        for(int i = 0; i < ordine_giocatori.size(); i++){
            std::cout << ordine_giocatori[i] << ", ";
        }

        std::vector<RobotPlayer*> in_order;
        for(int i = 0; i < ordine_giocatori.size(); i++){
            if(ordine_giocatori[i] == a.get_player()) in_order.push_back(&a);
            else if(ordine_giocatori[i] == b.get_player()) in_order.push_back(&b);
            else if(ordine_giocatori[i] == c.get_player()) in_order.push_back(&c);
            else if(ordine_giocatori[i] == d.get_player()) in_order.push_back(&d);
        }
        for(int i = 0; i < ordine_giocatori.size(); i++){
            std::cout << "ordine player rimasti " << in_order[i] << "\n";
        }


        while(turns < 70 && Player::num_player != 1){
            for(int i = 0 ; i < ordine_giocatori.size(); i++){
                in_order[i] -> auto_turn();
                if(in_order[i] -> get_player() == 0){

                    //non posso usare erase() per il vettore di puntatori poichè mi va a deallocare la memoria a cui punta il puntatore
                    /* ordine_giocatori.erase(ordine_giocatori.begin() + i); */
                    int temp = ordine_giocatori[ordine_giocatori.size() -1];
                    ordine_giocatori[i] = temp;
                    ordine_giocatori.pop_back();
                    sort(ordine_giocatori.begin(), ordine_giocatori.end(), std::greater<int>());

                    for(int i = 0; i < ordine_giocatori.size(); i++){
                        if(ordine_giocatori[i] == a.get_player()) in_order[i] = &a;
                        else if(ordine_giocatori[i] == b.get_player()) in_order[i] = &b;
                        else if(ordine_giocatori[i] == c.get_player()) in_order[i] = &c;
                        else if(ordine_giocatori[i] == d.get_player()) in_order[i] = &d;
                    }
                    for(int j = 0; j < ordine_giocatori.size(); j++){
                        std::cout << "giocatore rimasto: " << in_order[j] -> get_player() << ", ";
                    }
                }
            }
            turns++;
            std::cout << "number players " << Player::num_player << "\n";
            std::cout << "turno " << turns << "\n";
        }
        std::cout << a.show_balance() << "\n";
        std::cout << b.show_balance() << "\n";
        std::cout << c.show_balance() << "\n";
        std::cout << d.show_balance() << "\n";
        std::vector<int> winners = winner(&a, &b, &c, &d);
        for(int i = 0; i < winners.size(); i++){
            std::cout << "Ha vinto il giocatore: " << winners[i] << "\n";
        }
    }
    else{

        HumanPlayer a(&game);
        RobotPlayer b(&game);
        RobotPlayer c(&game);
        RobotPlayer d(&game);
    }

    game.printTable();
    /* game.printTable(); */
}
