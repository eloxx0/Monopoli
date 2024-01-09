#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"

//array che mantiene l'ordine dei giocatori: i numeri scritti all'interno rappresentano
//l'identificativo dei giocatori nell'ordine in cui devono procedere a giocare
std::vector<int> ordine_giocatori;

//variabile che indica i turni giocati. Il numero di turni massimi è 100: dopo di questo, se il gioco non è ancora terminato,
//viene dichiarato un vincitore in base al bilancio
int turns = 0;

/* std::vector<int> winner(Player* a, Player* b, Player* c, Player* d){ */
/*     std::vector<int> winners; */
/*     int a_bal = a -> show_balance(); */
/*     int b_bal = b -> show_balance(); */
/*     int c_bal = c -> show_balance(); */
/*     int d_bal = d -> show_balance(); */

/* } */

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

    if(command.compare("computer")){

        RobotPlayer first(&game);
        RobotPlayer second(&game);
        RobotPlayer third(&game);
        RobotPlayer fourth(&game);

        while(turns < 100 && num_player > 1){
            first.auto_turn();
            second.auto_turn();
            third.auto_turn();
            fourth.auto_turn();
            turns++;
        }
    }
    else{

        HumanPlayer first(&game);
        RobotPlayer second(&game);
        RobotPlayer third(&game);
        RobotPlayer fourth(&game);
    }

    game.printTable();
    /* int i = 0; */
    /* while(i < 50){ */
    /*     if(h.get_player() != 0){ */
    /*         h.auto_turn(); */
    /*     } */
    /*     if(g.get_player() != 0){ */
    /*         g.auto_turn(); */
    /*     } */
    /*     if(s.get_player() != 0){ */
    /*         s.auto_turn(); */
    /*     } */
    /*     if(a.get_player() != 0){ */
    /*         a.auto_turn(); */
    /*     } */
    /*     if(h.get_player() != 0){ */
    /*         std::cout << "soldi 1 " << h.show_balance() << "\n"; */
    /*     } */
    /*     if(g.get_player() != 0){ */
    /*         std::cout << "soldi 2 " << g.show_balance() << "\n"; */
    /*     } */
    /*     if(s.get_player() != 0){ */
    /*         std::cout << "soldi 3 " << s.show_balance() << "\n"; */
    /*     } */
    /*     if(a.get_player() != 0){ */
    /*         std::cout << "soldi 4 " << a.show_balance() << "\n"; */
    /*     } */
    /*     game.printTable(); */
    /*     i++; */
    /* } */

    /* int count = 0; */
    /* game.printTable(); */
}
