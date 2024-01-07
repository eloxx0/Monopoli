#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"

int main(){
    GameTable game;
    RobotPlayer h(&game);
    RobotPlayer g(&game);
    RobotPlayer s(&game);
    RobotPlayer a(&game);
    int i = 0;
    while(i < 150){
        if(h.get_player() != 0){
            h.auto_turn();
        }
        if(h.get_player() != 0){
            g.auto_turn();
        }
        if(h.get_player() != 0){
            s.auto_turn();
        }
        if(h.get_player() != 0){
            a.auto_turn();
        }
        if(h.get_player() != 0){
            std::cout << "soldi h " << h.show_balance() << "\n";
        }
        if(h.get_player() != 0){
            std::cout << "soldi g " << g.show_balance() << "\n";
        }
        if(h.get_player() != 0){
            std::cout << "soldi s " << s.show_balance() << "\n";
        }
        if(h.get_player() != 0){
            std::cout << "soldi a " << a.show_balance() << "\n";
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
