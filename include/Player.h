#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include "GameTable.h"
#include "Casella.h"

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
//
//
//il giocatore deve avere accesso diretto alle caselle del tabellone tramite la sua posizione definita,
//che indica la casella corrispondente nell'array che forma il tabellone

//non è possibile instanziare oggetti Player, necessario specificare HumanPlayer o RobotPlayer

//variabile statica che serve per tenere il conto dei giocatori inizializzati.
//Ad ogni giocatore viene associato un numero identificativo univoco in base
//a quanti giocatori sono già presenti nella partita
static int num_player = 0;

class Player{

    //protected in modo che le classi derivate ereditino i dati membro
    protected:

        //puntatore alla tabella di gioco associata al giocatore
        GameTable* table_p;

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

        //disabilita copia e costruttore di copia per la classe Player: ogni volta in cui si
        //prova a copiare oggetti Player viene lanciato un errore in compilazione
        //impedisce che l'oggetto venga costruito di default da una classe derivata

        Player(const Player&) = delete;

        Player& operator =(const Player&) = delete;

        Player(){}

        int show_balance() const{
            return balance;
        }

        //indica quantità da aggiungere o sottrarre al bilancio totale
        //(positivo se da aggiungere, negativo se da togliere)
        void edit_balance(int bal){
            balance += bal;
        }

        int get_position() const{
            return position;
        }

        void set_position(int pos){
            position = pos;
        }

        int get_player(){
            return player;
        }

        //tenta di comprare la casella in cui si trova attualmente il giocatore, 
        //verificando che il bilancio sia adeguato.
        //l'esito varia se il giocatore è umano o robot
        virtual void buy_slot() = 0;

        //tenta di comprare una casa nella casella attuale. Operazione possibile
        //solo se la casella è già di proprietà del giocatore.
        virtual void buy_house() = 0;

        //tenta di comprare un albergo nella casella attuale. Operazione possibile
        //solo se la casella è già di proprietà del giocatore e contiene una casa. 
        virtual void buy_hotel() = 0;


        //metodo che fa lanciare il dado al giocatore e lo fa avanzare di posizione nel tabellone.
        //Se passa per il via ritira 20 fiorini
        void advance();

        //stampa le informazioni principali del player: nome giocatore(in base alla pedina
        //e/o numero identificativo) e posizione (in coordinate sul tabellone)
        //
        //Ha senso come metodo interno alla classe?
        void print_player();

        //la stampa delle proprietà(caselle che contengono case/alberghi, lista
        //delle proprietà possedute da ogni giocatore) deve essere gestita nel
        //tabellone poichè le informazioni necessarie sono salvate li


};
//restituisce una stringa che contiene la posizione IN COORDINATE!
//forse meglio gestirla nel tabellone?
//le coordinate sono definite con colonne che vanno da 1 a 8 e 
//righe che vanno da A ad H
std::string string_pos(int pos);


//funzione che restituisce il numero ottenuto dalla somma del lancio di due dadi, generato
//casualmente
int throw_dice();


#endif //PLAYER_H
