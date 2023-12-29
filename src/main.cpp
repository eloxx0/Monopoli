#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"



int main(){
    GameTable game;
    HumanPlayer h;
    std::cout << h.get_player() << " " << h.show_balance() << "\n";
    h.advance();
    h.add_balance(-20);
    std::cout << h.get_position() << " " << h.show_balance() << "\n";
    Casella i = game.table[0];
    std::cout << h.get_player();
    std::cout << h.show_balance() << "\n";
    std::cout << throw_dice();
}
