#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"



int main(){
    GameTable game;
    HumanPlayer h(&game);
    RobotPlayer g(&game);
    h.advance();
    h.buy_slot();
    g.edit_balance(-95);
    g.advance();
    g.buy_slot();
    std::cout << "h posizione " << h.get_position() << " " << h.show_balance() << "\n";
    std::cout << "g posizione " << g.get_position() << " " << g.show_balance() << "\n";
    std::cout << "h: "<< h.get_player() << "\n";
    std::cout << "g: "<< g.get_player() << "\n";
    std::cout << "soldi g " << g.show_balance() << "\n";
    std::cout << "soldi h " << h.show_balance() << "\n";
    game.printTable();
}
