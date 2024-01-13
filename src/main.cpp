// LISA BUONOCORE

#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"
#include <bits/stdc++.h>
#include <algorithm>

// array che mantiene l'ordine dei giocatori: i numeri scritti all'interno rappresentano
// l'identificativo dei giocatori nell'ordine in cui devono procedere a giocare
std::vector<int> ordine_giocatori;

std::vector<RobotPlayer *> in_order;

// variabile che indica i turni giocati. Il numero di turni massimi è 60 per i computer, 20 con il player umano:
// dopo di questo, se il gioco non è ancora terminato, viene dichiarato un vincitore(o più vincitori, in caso di pareggio) in base al bilancio
int turns = 0;

// funzione che riordina i giocatori in base all'array contenente i risultati ottenuti dal lancio dei dadi.
// Viene dato per scontato che il valore in posizione 0 rappresenta il numero ottenuto dal lacio del dado del
// player numero 1, quello in posizione 1 dal lancio del dado del player numero 2 e così via
void player_order(int disordered_results[4])
{
    int ordered_results[4] = {disordered_results[0], disordered_results[1], disordered_results[2], disordered_results[3]};
    std::sort(ordered_results, ordered_results + 4, std::greater<int>());
    for (int i = 0; i < 4; i++)
    {
        if (ordered_results[i] == disordered_results[0])
            ordine_giocatori.push_back(1);
        else if (ordered_results[i] == disordered_results[1])
            ordine_giocatori.push_back(2);
        else if (ordered_results[i] == disordered_results[2])
            ordine_giocatori.push_back(3);
        else if (ordered_results[i] == disordered_results[3])
            ordine_giocatori.push_back(4);
    }
}

//funzione che riempie il vettore in_order con i puntatori dei robotplayer in ordine di gioco
//(0 se il player è umano)
void robot_vector_order(RobotPlayer* a, RobotPlayer* b, RobotPlayer* c, RobotPlayer* d){

    for (int i = 0; i < ordine_giocatori.size(); i++)
    {
        //poichè il giocatore umano è sempre il primo giocatore, e al posto di passare il giocatore umano
        //al metodo passo 0, vado a controllare che a sia diverso da 0
        if (a != 0 && ordine_giocatori[i] == a -> get_player()){
            in_order.push_back(a);
        }
        else if (ordine_giocatori[i] == b -> get_player()){
            in_order.push_back(b);
        }
        else if (ordine_giocatori[i] == c -> get_player()){
            in_order.push_back(c);
        }
        else if (ordine_giocatori[i] == d -> get_player()){
            in_order.push_back(d);
        }
        else{
            in_order.push_back(0);
        }
    }
}

//funzione che gestisce l'eliminazione di un player dalla partita
void delete_player(int pos, RobotPlayer* a, RobotPlayer* b, RobotPlayer* c, RobotPlayer* d){

    ordine_giocatori.erase(ordine_giocatori.begin() + pos);
    in_order.erase(in_order.begin() + pos);
}
// funzione che permette di iniziare il gioco facendo lanciare i dadi ai giocatori e decidendo i turni. Viene dato per
// scontato che il primo valore(a_val) viene ottenuto dal giocatore 1, il secondo(b_val) dal giocatore 2 e così via.
void start_game()
{

    int a_val = throw_dice();
    int b_val = throw_dice();
    int c_val = throw_dice();
    int d_val = throw_dice();
    // faccio ritirare i dadi finchè non sono diversi tutti i valori
    int results[4] = {a_val, b_val, c_val, d_val};

    test:
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (results[i] == results[j])
                {
                    results[j] = throw_dice();
                    // se deve ritirare i dadi, rieffettua il controllo sul nuovo array ottenuto
                    goto test;
                }
            }
        }
    // copio i nuovi valori nelle variabili
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
    for (int i = 0; i < ordine_giocatori.size(); i++)
    {
        std::cout << ordine_giocatori[i];
        if (i != ordine_giocatori.size() - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
}

void show(GameTable *game, HumanPlayer *a, RobotPlayer *b, RobotPlayer *c, RobotPlayer *d)
{
    game->printTable(); // visualizzare il tabellone
    // printa il bilancio di ogni giocatore ancora valido
    if (a->get_player() != 0)
        std::cout <<"Il giocatore 1 possiede: "<< a->show_balance() << " fiorini\n";
    if (b->get_player() != 0)
        std::cout <<"Il giocatore 2 possiede: "<< b->show_balance() << " fiorini\n";
    if (c->get_player() != 0)
        std::cout <<"Il giocatore 3 possiede: "<< c->show_balance() << " fiorini\n";
    if (d->get_player() != 0)
        std::cout <<"Il giocatore 4 possiede: "<< d->show_balance() << " fiorini\n";
    // printa i possedimenti associati ad ogni player
    game->print_legenda(a->get_player());
    game->print_legenda(b->get_player());
    game->print_legenda(c->get_player());
    game->print_legenda(d->get_player());
}

void human_play(HumanPlayer *a, RobotPlayer *b, RobotPlayer *c, RobotPlayer *d, GameTable *game)
{
    int a_pos = a->get_position();
    int buy;
    //caso in cui non posso comprare la casella (o perchè è un albergo, o perchè è di proprietà di altri)
    if(game -> table[a_pos].player_buyable(a -> get_player()) == 0 || a_pos % 7 == 0 || a_pos == 0){
        goto endturn;
    }
    else if(game -> table[a_pos].player_buyable(a -> get_player()) != 0){
        buy = game -> table[a_pos].player_buyable(a -> get_player());
        //se può comprare il terreno
        command:
        if(buy == 1){
            std::cout << "Desidera comprare questa casella? Rispondere S per sì, N per no e show per mostrare lo status\n";
            std::string r1;
            std::cin.clear();
            std::getline(std::cin >> std::ws, r1);
            if (r1.compare("show") == 0)
            {
                show(game, a, b, c, d);
                goto command;
            }
            else if (r1.compare("S") == 0 || r1.compare("s") == 0)
            {
                a->buy_slot();
            }
            else if (r1.compare("N") == 0 || r1.compare("n") == 0)
            {
                std::cout << "Ok, non compri il terreno\n";
            }
            else
            {
                std::cout << "comando invalido\n";
                goto command;
            }
        }
        //se può comprare la casa
        else if(buy == 2){
            std::cout << "Desidera comprare questa casa? Rispondere S per sì, N per no e show per mostrare lo status\n";
            std::string r1;
            std::cin.clear();
            std::getline(std::cin >> std::ws, r1);
            if (r1.compare("show") == 0)
            {
                show(game, a, b, c, d);
                goto command;
            }
            else if (r1.compare("S") == 0 || r1.compare("s") == 0)
            {
                a->buy_slot();
            }
            else if (r1.compare("N") == 0 || r1.compare("n") == 0)
            {
                std::cout << "Ok, non compri la casa\n";
            }
            else
            {
                std::cout << "comando invalido\n";
                goto command;
            }
        }
        //se può comprare l'hotel
        else if(buy == 3){
            std::cout << "Desidera comprare questo hotel? Rispondere S per sì, N per no e show per mostrare lo status\n";
            std::string r1;
            std::cin.clear();
            std::getline(std::cin >> std::ws, r1);
            if (r1.compare("show") == 0)
            {
                show(game, a, b, c, d);
                goto command;
            }
            else if (r1.compare("S") == 0 || r1.compare("s") == 0)
            {
                a->buy_slot();
            }
            else if (r1.compare("N") == 0 || r1.compare("n") == 0)
            {
                std::cout << "Ok, non compri l'hotel\n";
            }
            else
            {
                std::cout << "comando invalido\n";
                goto command;
            }
        }
    }

    endturn:
        std::cout << "Non posso più fare nulla in questo turno.\n";
        std::cout << "Inserire il comando show se si vuol visualizzare lo status della partita, qualsiasi altra cosa "
            << " per terminare il turno\n";
        std::string request;
        std::cin.clear();
        std::getline(std::cin >> std::ws, request);
        if (request.compare("show") == 0)
        {
            show(game, a, b, c, d);
        }
        std::cout << "turno terminato\n";
}

//funzione che determina i vincitori della partita e li stampa sia su log.txt che su terminale
void winner(Player *a, Player *b, Player *c, Player *d)
{

    print_double("Partita teriminata!\n");

    print_double("Bilancio finale del giocatore 1: " + std::to_string(a->show_balance()) + "\n");
    print_double("Bilancio finale del giocatore 2: " + std::to_string(b->show_balance()) + "\n");
    print_double("Bilancio finale del giocatore 3: " + std::to_string(c->show_balance()) + "\n");
    print_double("Bilancio finale del giocatore 4: " + std::to_string(d->show_balance()) + "\n");
    std::vector<int> winners;

    int a_bal = a->show_balance();
    int b_bal = b->show_balance();
    int c_bal = c->show_balance();
    int d_bal = d->show_balance();

    //inserisco tutti i bilanci nel vettore
    winners.push_back(a_bal);
    winners.push_back(b_bal);
    winners.push_back(c_bal);
    winners.push_back(d_bal);
    int max = *max_element(winners.begin(), winners.end());

    //li metto in ordine decrescente
    std::sort(winners.begin(), winners.end(), std::greater<int>());

    int size = winners.size();
    for (int i = size - 1; i > 0; i--)
    {
        if (winners[i] < max){
            winners.pop_back();
        }
    }
    std::vector<int> number_winners;
    if (std::binary_search(winners.begin(), winners.end(), a_bal))
    {
        number_winners.push_back(1);
    }
    if (std::binary_search(winners.begin(), winners.end(), b_bal))
    {
        number_winners.push_back(2);
    }
    if (std::binary_search(winners.begin(), winners.end(), c_bal))
    {
        number_winners.push_back(3);
    }
    if (std::binary_search(winners.begin(), winners.end(), d_bal))
    {
        number_winners.push_back(4);
    }
    for (int i = 0; i < number_winners.size(); i++)
    {
        print_double("Ha vinto il giocatore: " + std::to_string(number_winners[i]) + " in " + std::to_string(turns) + " turni\n");
    }
}




int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Necessario inserire \"bin/main computer\" o \"bin/main human\" in base alla modalità di gioco desiderata. Riprovare\n";
        return 0;
    }
    std::string command(argv[1]);

    if (command.compare("computer") != 0 && command.compare("human") != 0)
    {
        std::cerr << " Comandi sconosciuti: inserire \"computer\" o \"human\" in base alla modalità di gioco\n";
        return 0;
    }

    // creazione del file di log su cui vado a stampare la partita
    std::ofstream file;
    file.open("log.txt", std::ios::out);
    GameTable game;

    // GESTIONE 4 COMPUTER
    if (command.compare("computer") == 0)
    {

        RobotPlayer a(&game);
        RobotPlayer b(&game);
        RobotPlayer c(&game);
        RobotPlayer d(&game);

        start_game();

        // creato il vettore con i puntatori dei giocatori in ordine in base al turno di gioco. Viene utilizzato il fatto
        // che il vettore ordine_giocatori contiene il numero identificativo del giocatore nell'ordine in cui devono giocare
        robot_vector_order(&a, &b, &c, &d);

        // la partita termina quando rimane un unico giocatore oppure terminano i turni
        while (turns < 60 && Player::num_player != 1)
        {
            for (int i = 0; i < ordine_giocatori.size(); i++)
            {
                in_order[i]->auto_turn();
                //se il giocatore robot durante l'autoturn è stato eliminato(cioè il suo numero giocatore
                //è stato settato a 0) viene eliminato dal vettore di puntatori mantenendo inalterato 
                //l'ordine di gioco
                if (in_order[i]->get_player() == 0)
                {
                    delete_player(i, &a, &b, &c, &d);
                }
            }
            game.printTable();
            game.print_legenda(a.get_player());
            game.print_legenda(b.get_player());
            game.print_legenda(c.get_player());
            game.print_legenda(d.get_player());
            turns++;
        }

        winner(&a, &b, &c, &d);
    }
    else
    {
        // GESTIONE 1 UTENTE 3 COMPUTER
        HumanPlayer a(&game);
        RobotPlayer b(&game);
        RobotPlayer c(&game);
        RobotPlayer d(&game);

        start_game();

        //****attenzione alla differenza tra il turno di gioco e il turno del giocatore all'interno del turno!!****
        int human_turn;
        auto find = std::find(ordine_giocatori.begin(), ordine_giocatori.end(), 1);
        human_turn = find - ordine_giocatori.begin();
        // inserisce in human_turn il numero di turno del giocatore in ordine rispetto agli altri giocatori
        print_double("Giochi come giocatore 1 nel turno " + std::to_string(human_turn + 1) + "\n");
        
        // inserisce nel vettore solo i giocatori Robot, 0 al posto del giocatore umano:
        // il turno del giocatore umano viene gestito a parte
        robot_vector_order(0, &b, &c, &d);

        while (turns < 20 && Player::num_player != 1)
        {
            // viene reimpostato a 0 all'inizio di ogni turno poichè serve per indicare a che fase del turno ci troviamo
            int count_in_turn = 0;
            for (int i = 0; i < ordine_giocatori.size(); i++)
            {
                if (count_in_turn == human_turn)
                {
                    a.advance();
                    // tenta il pagamento se la casella appartiene a qualcuno
                    a.pay_player();
                    // gestione caso in cui il giocatore viene eliminato
                    if (a.get_player() == 0)
                    {
                        //settato human_turn a -1 in modo che non sia più possibile giocare con il giocatore umano
                        human_turn = -1;
                        delete_player(i, 0, &b, &c, &d);
                    }
                    else
                    {
                        human_play(&a, &b, &c, &d, &game);
                    }
                    count_in_turn++;
                }
                else
                {
                    in_order[i]->auto_turn();
                    if (in_order[i]->get_player() == 0)
                    {
                        delete_player(i, 0, &b, &c, &d);
                    }
                    count_in_turn++;
                }
            }
            turns++;
        }
        winner(&a, &b, &c, &d);
    }

    game.printTable();
    file.close();
}
