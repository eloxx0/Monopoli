#ifndef CASELLA
#define CASELLA
#include <iostream>


//definisco la classe Casella nel .h per fare in modo che le diverse classi siano in grado di operare
//l'una sull'altra. In questo modo mi basta includere il .h nel cpp per evitare problemi
//di inclusione ricorsiva

class Player;

class Casella{

    private:
    
    char status; //caratteristica casella se eco/standard/vuota/lusso
    Player* player;
    int belongings; // possedimenti da parte del player, 1 se terreno, 2 presenza di una casa, 3 presenza di un albergo, 0 se per quella determinata casella il player non possiede nulla
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter/setter lusso/eco/standard tramite status
    //setter e getter
    
    Player* get_propriety(){    //ritorna puntatore a player 
        return player;
    }

    void set_propriety(Player* p){
        if(p == nullptr){
            set_belongings(0);
        }
        player = p;
    }

    //ritorna il costo della casella da comprare
    int get_cost();

    //ritorna il costo del pernottamento se la casella presenta una casa o un albergo
    int get_price();

    //ritorna il numero del giocatore che possiede la casella
    int number_player();
    
    char get_status() const{    //getter status
        return status;
    }
    
    void set_status(char x){
        status=x;
    }
    
    void set_belongings(int x){ //check operazione
        if(x >=0 && x<4) belongings=x;
        else std::cout<<"Impossibile effettuare l'operazione"<<std::endl;
    }
    
    int get_belongings() const{ //getter possedimenti per il giocatore rispetto ad una casella
        return belongings;
    }  

    //ritorna 0 se il terreno non è comprabile dal giocatore(o perchè presenta già un hotel
    //oppure perchè presenta ) con il numero identificativo passato per parametro,
    //1 se è comprabile, 2 se è possibile comprare una casa, 3 se è possibile comprare un hotel
    int player_buyable(int player);

};

std::string print_casella(Casella& c);

#endif // CASELLA
