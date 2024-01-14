// ELOISA PAGANI

#include "../include/Player.h"

// variabile statica che indica il numero di giocatori presenti nella partita, inizializzata a 0 a inizio del gioco
int Player::num_player = 0;

void Player::advance()
{
    int a = throw_dice();
    print_double("Giocatore " + std::to_string(player) + " ha tirato i dadi ottenendo un valore di " + std::to_string(a) + "\n");

    // incrementa la posizione attuale di a
    int new_pos = position + a;
    if (new_pos > 27)
    {
        print_double("Giocatore " + std::to_string(player) + " passato per il via! Ritira 20 fiorini\n");
        edit_balance(20);
        // se si trova sulla posizione 28, cioè sullo start, diventa posizione 0
        new_pos = new_pos % 28;
    }
    set_position(new_pos);
    print_double("Giocatore " + std::to_string(player) + " arriva in posizione " + conversion_table(position) + "\n");
    // setta la nuova posizione del giocatore nell'array del tabellone che gestisce le posizioni
    table_p->set_player_pos(player, position);
}

bool Player::pay_player()
{

    Casella *temp = &(table_p->table[position]);

    // controlla che la casella sia di proprietà di un altro player, e che ci sia una casa o un hotel, altrimenti non è
    // necessario pagare nulla
    if (temp->number_player() != player && temp->number_player() != 0 && temp->get_belongings() > 1)
    {
        int price = temp->get_price();

        // gestisco l'eliminazione del giocatore nel caso in cui non può pagare il pernottamento nel suo totale
        if (price > balance)
        {

            print_double("Impossibile pagare pernottamento: saldo troppo basso! Giocatore " + std::to_string(player) + " eliminato\n");

            // paga tutti i soldi rimanenti all'altro giocatore
            price = balance;
            print_double("Giocatore " + std::to_string(player) + " paga il prezzo di " + std::to_string(price) + " fiorini al giocatore " + std::to_string(temp->number_player()) + "\n");
            //giocatore eliminato rimane con saldo negativo a -1
            edit_balance(-price -1);
            temp->get_propriety()->edit_balance(price);

            delete_player();
            // ritorna true poichè il pagamento è stato fatto con i soldi rimanenti nel bilancio del giocatore
            return true;
        }

        print_double("Giocatore " + std::to_string(player) + " paga il prezzo di " + std::to_string(price) + " fiorini al giocatore " + std::to_string(temp->number_player()));
        print_double(" per il pernottamento nella casella " + conversion_table(position) + "\n");
        edit_balance(-price);
        temp->get_propriety()->edit_balance(price);

        return true;
    }
    // Se il terreno non è di proprietà del player ma non ha nè una casa nè un albergo
    else if (temp->number_player() != player && temp->number_player() != 0 && temp->get_belongings() == 1)
    {

        std::cout << "il terreno è di proprietà di " << temp->number_player() << ". Non devo pagare nulla\n";
        // ritorna true poichè il terreno è già di qualcuno, ma non è necessario effettuare il pagamento al giocatore
        return true;
    }
    return false;
}

void Player::delete_player()
{

    // posizione nella tabella settata a -1 in modo che il valore non valido indichi al tabellone che il
    // giocatore è stato eliminato
    table_p->set_player_pos(player, -1);

    // vado a controllare tutte le proprietà del player e le setto a 0
    for (int i = 0; i < 28; i++)
    {

        if (table_p->table[i].number_player() == player)
        {

            // settato il puntatore nella casella che possiede a nullptr
            table_p->table[i].set_propriety(nullptr);
        }
    }

    player = 0;

    // viene decrementata la variabile che indica il numero di player: quando il
    // numero di player scende sotto il 2, il giocatore rimasto ha vinto
    Player::num_player--;
}

int throw_dice()
{

    // imposta come seed del generatore randomico il tempo attuale e lo randomizza ulteriormente
    std::srand(std::time(nullptr) + rand());
    int a = 1 + (std::rand() % 6);
    int b = 1 + (std::rand() % 6);
    return a + b;
}
