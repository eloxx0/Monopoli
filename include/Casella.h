#ifndef CASELLA
#define CASELLA
//#include "Player.h"
#include <iostream>

class Casella{

    private:
    
    char status; 
    int propriety;
    //secondo me sono da definire come dei bool, come fossero uno switch
    bool house;
    bool hotel;
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter lusso/eco/standard tramite status?
    //setter e getter
    
    int get_propriety(void){    //ritorna numero player casella oppure 0 se non la possiede nessuno, dovrei avere accesso a player?
        return propriety;
    }
    
    void set_house(bool x){
        house=x;
    }
    
    void set_hotel(bool x){ //piccolo check per questa operazione
        if(house) hotel=x;
        else std::cout<<"Impossibile effettuare questa operazione"<<std::endl;
    }
    
    bool get_house() const{
        return house;
    }
    
    bool get_hotel() const{
        return hotel;
    }  

};

#endif // CASELLA
