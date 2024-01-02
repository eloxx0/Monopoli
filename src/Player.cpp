#include "../include/Player.h"

//il tabellone è formato da 28 caselle disposte come ai lati di un quadrato 8x8
//la prima e ultima riga possiedono 8 caselle ciascuna, tutte quelle in mezzo ne possiedono 2
std::string string_pos(int pos){
    return 0;
}

void Player::advance(){
    int a = throw_dice();
    std::cout << "Giocatore " << player << " avanza di " << a << " posizioni!" << std::endl;
    //incrementa la posizione attuale di a
    int new_pos = position + a;
    if(new_pos > 27){
        std::cout << "Passato per il via! Ritira 20 fiorini" << std::endl;
        add_balance(20);
        //se si trova sulla posizione 28, cioè sullo start, diventa posizione 1
        new_pos = new_pos % 27;
    }
    set_position(new_pos);

}

void Player::print_player(){
    std::cout << "Giocatore " << player << " nella casella " << string_pos(position);
}

int throw_dice(){
    //imposta come seed del generatore randomico il tempo attuale
    std::srand(std::time(0));
    int a = 1 + (std::rand() % 6);
    int b = 1 + (std::rand() % 6);
    return a+b;
}
