// ELOISA PAGANI

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "GameTable.h"

// definisco la classe Casella nel .h per fare in modo che le diverse classi siano in grado di operare
// l'una sull'altra. In questo modo mi basta includere il .h nel cpp per evitare problemi
// di inclusione ricorsiva
class Casella;

// Giocatore generico. Ogni giocatore possiede un saldo iniziale
// fissato a 100 fiorini.
// Ogni giocatore può tirare un dado e comprare determinate caselle
// se il saldo glielo permette. L'operazione effettuata dipende dalla
// casella di gioco in cui si trova
// La posizione nel tabellone viene salvata nel giocatore, e viene aggiornata
// ad ogni turno.
// il giocatore deve avere accesso diretto alle caselle del tabellone tramite la sua posizione definita,
// che indica la casella corrispondente nell'array che forma il tabellone

// non è possibile instanziare oggetti Player, necessario specificare HumanPlayer o RobotPlayer

class Player{

// protected in modo che le classi derivate ereditino i dati membro
protected:
    // puntatore alla tabella di gioco associata al giocatore
    GameTable *table_p;

    // indica il saldo di ogni giocatore. Il saldo iniziale è settato a 100 fiorini per ogni giocatore
    int balance = 100;

    // per ogni giocatore viene identificata la posizione all'interno della
    // tabella. Ogni posizione è identificata in modo univoco da una posizione
    // all'interno del tabellone, che poi viene convertita nelle coordinate
    // visualizzate sul tabellone
    // la posizione di base per ogni giocatore è sulla casella di Start, cioè la
    // casella 0 nel tabellone
    int position = 0;

    // per ogni giocatore viene definito il numero identificativo univocamente e
    // in modo sequenziale in base all'ordine di creazione dell'oggetto e in based a quanti
    // altri oggetti sono già stati creati
    int player;

    // funzione chiamata quando un player viene eliminato da una determinata partita
    void delete_player();

public:
    // variabile statica che serve per tenere il conto dei giocatori inizializzati.
    // Ad ogni giocatore viene associato un numero identificativo univoco in base
    // a quanti giocatori sono già presenti nella partita.
    static int num_player;

    // disabilita copia e costruttore di copia per la classe Player: ogni volta in cui si
    // prova a copiare oggetti Player viene lanciato un errore in compilazione
    // impedisce che l'oggetto venga costruito di default da una classe derivata

    Player(const Player &) = delete;

    Player &operator=(const Player &) = delete;

    Player() {}

    int show_balance() const
    {
        return balance;
    }

    // indica quantità da aggiungere o sottrarre al bilancio totale
    //(positivo se da aggiungere, negativo se da togliere)
    void edit_balance(int bal)
    {
        balance += bal;
    }

    //ritorna la posizione del giocatore nell'array della tabella, non le coordinate
    int get_position() const
    {
        return position;
    }

    //imposta la posizione del giocatore nell'array
    void set_position(int pos)
    {
        position = pos;
    }

    // ritorna il numero identificativo del player
    int get_player() const
    {
        return player;
    }

    // tenta di comprare la casella in cui si trova attualmente il giocatore,
    // verificando che il bilancio sia adeguato.
    // l'esito varia se il giocatore è umano o robot
    virtual void buy_slot() = 0;

    // tenta di comprare una casa nella casella attuale. Operazione possibile
    // solo se la casella è già di proprietà del giocatore.
    virtual void buy_house() = 0;

    // tenta di comprare un albergo nella casella attuale. Operazione possibile
    // solo se la casella è già di proprietà del giocatore e contiene una casa.
    virtual void buy_hotel() = 0;

    // paga al giocatore che possiede la casella su cui si trova il giocatore chiamante
    // il pernottamento: Ritorna true se è stato pagato il pernottamento, o eliminato il giocatore,
    // false altrimenti
    bool pay_player();

    // metodo che fa lanciare il dado al giocatore e lo fa avanzare di posizione nel tabellone.
    // Se passa per il via ritira 20 fiorini
    void advance();
};

// funzione che restituisce il numero ottenuto dalla somma del lancio di due dadi, generato
// casualmente
int throw_dice();

#endif // PLAYER_H
