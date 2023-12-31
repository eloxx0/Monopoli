#include "../include/Player.h"

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
            
            //posizione nella tabella settata a -1 in modo che il valore non valido indichi al tabellone che il 
            //giocatore è stato eliminato
            table_p -> set_player_pos(player, -1);

            //vado a controllare tutte le proprietà del player e le setto a 0
            for(int i =0 ; i < 28; i++){

                if(table_p -> table[i].number_player() == player){

                    table_p -> table[i].set_propriety(nullptr);
                }
            }

            //paga tutti i soldi rimanenti all'altro giocatore
            price = balance;
            std::cout << "giocatore " << player << " paga il prezzo di " << price << " a " << temp -> number_player() << "\n";
            edit_balance(-price);
            temp -> get_propriety() -> edit_balance(price);
            
            //settato il puntatore nella casella che possiede a nullptr
            player = 0;

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
    //Se il terreno non è di proprietà del player ma non ha nè una casa nè un albergo
    else if(temp -> number_player() != player && temp -> number_player() != 0 && temp -> get_belongings() == 1){
        std::cout << "il terreno è di proprietà di " << temp -> number_player() << ". Non devo pagare nulla\n";
        //ritorna true poichè il terreno è già di qualcuno, ma non è necessario effettuare il pagamento al giocatore
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
