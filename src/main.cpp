#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"
#include <algorithm>

//array che mantiene l'ordine dei giocatori: i numeri scritti all'interno rappresentano
//l'identificativo dei giocatori nell'ordine in cui devono procedere a giocare
int ordine_giocatori[4];

int main(){
    GameTable game;
    RobotPlayer h(&game);
    RobotPlayer g(&game);
    RobotPlayer s(&game);
    RobotPlayer a(&game);
    game.printTable();
    int i = 0;
    while(i < 15){
        if(h.get_player() != 0){
            h.auto_turn();
        }
        if(g.get_player() != 0){
            g.auto_turn();
        }
        if(s.get_player() != 0){
            s.auto_turn();
        }
        if(a.get_player() != 0){
            a.auto_turn();
        }
        if(h.get_player() != 0){
            std::cout << "soldi 1 " << h.show_balance() << "\n";
        }
        if(g.get_player() != 0){
            std::cout << "soldi 2 " << g.show_balance() << "\n";
        }
        if(s.get_player() != 0){
            std::cout << "soldi 3 " << s.show_balance() << "\n";
        }
        if(a.get_player() != 0){
            std::cout << "soldi 4 " << a.show_balance() << "\n";
        }
        game.printTable();
        i++;
    }
    /* h.advance(); */
    /* h.buy_slot(); */
    /* g.edit_balance(-95); */
    /* g.advance(); */
    /* g.buy_slot(); */
    /* std::cout << "h posizione " << h.get_position() << " " << h.show_balance() << "\n"; */
    /* std::cout << "g posizione " << g.get_position() << " " << g.show_balance() << "\n"; */
    /* std::cout << "h: "<< h.get_player() << "\n"; */
    /* std::cout << "g: "<< g.get_player() << "\n"; */
    /* std::cout << "soldi g " << g.show_balance() << "\n"; */
    /* std::cout << "soldi h " << h.show_balance() << "\n"; */
    game.printTable();
}
