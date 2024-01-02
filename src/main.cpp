#include "HumanPlayer.cpp"
#include "RobotPlayer.cpp"



int main(){
    GameTable game;
    HumanPlayer h(&game);
    RobotPlayer g(&game);
    std::cout << h.get_player() << " " << h.show_balance() << "\n";
    h.advance();
    h.add_balance(-20);
    RobotPlayer r(&game);
    std::cout << h.get_position() << " " << h.show_balance() << "\n";
    std::cout << "h: "<< h.get_player();
    std::cout << "g: "<< g.get_player();
    std::cout << "r: " << r.get_player();
    std::cout << h.show_balance() << "\n";
    std::cout << throw_dice();
}
