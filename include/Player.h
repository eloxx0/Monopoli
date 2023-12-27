#ifndef PLAYER_H
#define PLAYER_H

//Giocatore generico. Ogni giocatore possiede un saldo iniziale
//fissato a 100 fiorini.
//Ogni giocatore può tirare un dado e comprare determinate caselle
//se il saldo glielo permette. L'operazione effettuata dipende dalla
//casella di gioco in cui si trova
//La posizione nel tabellone viene salvata nel giocatore, e viene aggiornata
//ad ogni turno.
//Ad ogni giocatore viene assegnato un numero identificativo da 1 a 4 in base
//al lancio iniziale dei dadi, che permetterà di identificare i turni di gioco
//e l'appartenenza delle caselle ad un determinato giocatore
//Decidere se è meglio definire in un vettore appartenente ad ogni giocatore
//le caselle possedute o se identificare il numero del giocatore
//all'interno della casella. Il secondo caso potrebbe risultare meno
//complesso poichè per identificare a chi appartiene una determinata 
//casella basta andare a guardare nella casella stessa


//non è possibile instanziare oggetti Player, necessario specificare HumanPlayer o RobotPlayer
class Player{

    private:


        //saldo iniziale di 100 fiorini per ogni giocatore
        int balance = 100;

        //per ogni giocatore viene identificata la posizione all'interno della
        //tabella. Ogni posizione è identificata in modo univoco da una posizione
        //all'interno del tabellone, che poi viene convertita nelle coordinate 
        //visualizzate sul tabellone
        //la posizione di base per ogni giocatore è sulla casella di Start, cioè la
        //casella 0 nel tabellone
        int position = 0;

        //per ogni giocatore viene definito il numero identificativo univocamente e
        //in modo sequenziale in base all'ordine di creazione/in base al
        //lancio del dado?. Ad ogni giocatore viene
        //assegnata una pedina? 
        int player;

    public:

        //ogni giocatore viene assegnata/può scegliere una pedina identificativa
        enum Pawns{
            dog = 1, hat, shoe, train, ship, car
        };

        //disabilita copia e costruttore di copia per la classe Player: ogni volta in cui si
        //prova a copiare oggetti Player viene lanciato un errore in compilazione
        //impedisce che l'oggetto venga costruito di default da una classe derivata
        
        //necessario anche se non viene allocata dinamicamente?

        Player(const Player&) = delete;

        Player& operator =(const Player&) = delete;

        Player(){}

        int show_balance() const{
            return balance;
        }

        //indica quantità da aggiungere o sottrarre al bilancio totale
        //(positivo se da aggiungere, negativo se da togliere)
        void change_balance(int bal){
            balance += bal;
        }

        int show_position() const{
            return position;
        }

        void set_position(int pos){
            position = pos;
        }

        void set_player(int num){
            player = num;
        }

        //ha senso ritornare bool? o semplicemente stampare l'esito
        
        //tenta di comprare la casella in cui si trova attualmente il giocatore, 
        //verificando che il bilancio sia adeguato.
        //ritorna true se l'acquisto è andato a buon fine, false altrimenti;
        //l'esito varia se il giocatore è umano o robot
        virtual bool buy_slot() = 0;

        //tenta di comprare una casa nella casella attuale. Operazione possibile
        //solo se la casella è già di proprietà del giocatore. Ritorna true 
        //se l'acquisto è andato a buon fine(se il credito è adeguato), false altrimenti.
        virtual bool buy_house() = 0;

        //tenta di comprare un albergo nella casella attuale. Operazione possibile
        //solo se la casella è già di proprietà del giocatore e contiene una casa. 
        //Ritorna true se l'acquisto è andato a buon fine(se il credito è adeguato),
        //false altrimenti.
        virtual bool buy_hotel() = 0;


};

//funzione che restituisce il numero ottenuto dalla somma del lancio di due dadi, generato
//casualmente
int throw_dice();


#endif //PLAYER_H
