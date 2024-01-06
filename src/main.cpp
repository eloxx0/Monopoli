#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"



int main(){
    GameTable game;
    HumanPlayer h(&game);
    RobotPlayer g(&game);
    std::cout << h.get_player() << " " << h.show_balance() << "\n";
    h.advance();
    int pos = h.get_position();
    game.table[pos].set_propriety(&g);
    h.buy_slot();
    std::cout << "h positione " << h.get_position() << " " << h.show_balance() << "\n";
    std::cout << "h: "<< h.get_player() << "\n";
    std::cout << "g: "<< g.get_player() << "\n";
    std::cout << "soldi g " << g.show_balance() << "\n";
    std::cout << "soldi h " << h.show_balance() << "\n";
    std::cout << throw_dice();
}
