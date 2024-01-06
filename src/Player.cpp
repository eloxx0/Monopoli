#include "../include/Player.h"

int Player::num_player = 0;

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
        edit_balance(20);
        //se si trova sulla posizione 28, cioè sullo start, diventa posizione 1
        new_pos = new_pos % 27;
    }
    Casella* temp = &(table_p -> table[position]);
    //se il player arriva sulla casella di un altro giocatore, gli paga il pernottamento. Se
    //non ha abbastanza soldi per pagare il pernottamento, viene eliminato
    if(temp -> get_number_p() != player){
        std::cout << "casella già posseduta da altri! Impossibile da comprare."
            << " Necessario pagare il pernottamento\n";
        int price = 14;
        if(price > balance){
            std::cout << "impossibile pagare pernottamento: saldo troppo basso!"
                << "giocatore " << player << " eliminato\n";
            //azzera tutte le variabili del giocatore
            player = 0;
            balance = 0;
            table_p = nullptr;
            position = 0;
            return;
        }
        edit_balance(-price);
        temp -> get_propriety() -> edit_balance(price);
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
