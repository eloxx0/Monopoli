/* #include "../include/Player.h" */
#include "../include/HumanPlayer.h"


HumanPlayer::HumanPlayer(){
    player = 1;

}

void HumanPlayer::buy_slot(){
    if (true){
        std::cout << "casella comprata";
    }
}

void HumanPlayer::buy_house(){
    return;
}

void HumanPlayer::buy_hotel(){
    return;
}

int main(){
    HumanPlayer h;
    std::cout << h.get_player();
    std::cout << h.show_balance() << "\n";
    std::cout << throw_dice();
}
