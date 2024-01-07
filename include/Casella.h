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
    int belongings; // possedimenti da parte del player, 0 se terreno, 1 presenza di una casa, 2 presenza di un albergo
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter/setter lusso/eco/standard tramite status
    //setter e getter
    
    Player* get_propriety(){    //ritorna puntatore a player 
        return player;
    }

    void set_propriety(Player* p){
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
        if(0<=x && x<=2) belongings=x;
        else std::cout<<"Impossibile effettuare l'operazione"<<std::endl;
    }
    
    int get_belongings() const{ //getter possedimenti
        return belongings;
    }  

};

std::ostream& operator<<(std::ostream& out, const Casella& x);

#endif // CASELLA
