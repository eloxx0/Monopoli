#ifndef CASELLA
#define CASELLA
//#include "Player.h"
#include <iostream>

class Casella{

    private:
    
    bool Lusso;
    bool Economica;
    bool Standard;
    //std::string status; 
    //secondo me sono da definire come dei bool, come fossero uno switch
    bool house;
    bool hotel;
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter lusso/eco/standard tramite status?
    //setter e getter
    void set_lusso(bool x){
        Lusso=x;
    }
    
    void set_economica(bool x){
        Economica=x;
    }
    
    void set_standard(bool x){
        Standard=x;
    }
    
    void set_house(bool x){
        house=x;
    }
    
    void set_hotel(bool x){ //piccolo check per questa operazione
        if(house==true) hotel=x;
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
