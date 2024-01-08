#include "../include/Player.h"
/* #include "../include/Casella.h" */

void Player::advance(){
    int a = throw_dice();
    std::cout << "Giocatore " << player << " avanza di " << a << " posizioni!" << std::endl;
    
    //incrementa la posizione attuale di a
    int new_pos = position + a;
    if(new_pos > 27){
        std::cout << "Passato per il via! Ritira 20 fiorini" << std::endl;
        edit_balance(20);
        //se si trova sulla posizione 28, cioè sullo start, diventa posizione 0
        new_pos = new_pos % 28;
    }
    set_position(new_pos);
    std::cout << "Giocatore " << player << " arriva in posizione " << position << std::endl;
    //setta la nuova posizione del giocatore nell'array del tabellone che gestisce le posizioni
    table_p -> set_player_pos(player, position);

}

bool Player::pay_player(){
    Casella* temp = &(table_p -> table[position]);

    //controlla che la casella sia di proprietà di un altro player, e che ci sia una casa o un hotel, altrimenti non è
    //necessario pagare nulla
    if(temp -> number_player() != player && temp -> number_player() !=0 && temp -> get_belongings() > 1){
        int price = temp -> get_price();
        if(price > balance){
            std::cout << "impossibile pagare pernottamento: saldo troppo basso!"
                << " Giocatore " << player << " eliminato\n";
            //azzera tutte le variabili del giocatore
            player = 0;
            balance = 0;
            table_p -> set_player_pos(player, -1);
            //posizione settata a -1, numero invalido, per indicare che il giocatore è fuori gioco
            position = -1;
            //viene decrementata la variabile che indica il numero di player: quando il 
            //numero di player scende sotto il 2, il giocatore rimasto ha vinto
            num_player--;
            return true;
        }
        std::cout << "giocatore " << player << " paga il prezzo di " << price << " a " << temp -> number_player() << "\n";
        edit_balance(-price);
        temp -> get_propriety() -> edit_balance(price);
        return true;
    }
    return false;
}

int throw_dice(){
    
    //imposta come seed del generatore randomico il tempo attuale e lo randomizza ulteriormente
    std::srand(std::time(nullptr) + rand());
    int a = 1 + (std::rand() % 6);
    int b = 1 + (std::rand() % 6);
    return a+b;

}
