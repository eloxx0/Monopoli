#ifndef CASELLA
#define CASELLA
#include <iostream>

class Casella{

    private:
    
    char status; 
    Player* player;
    int number_player;
    //definire come dei bool, come fossero uno switch
    bool house;
    bool hotel;
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter/setter lusso/eco/standard tramite status
    //setter e getter
    
    Player* get_propriety(void){    //ritorna puntatore a player
        return &player;
    }
    
    int get_number(void) const{       //???
        return number_player;
    }
    
    char get_status(void) const{
        return status;
    }
    
    void set_status(char x){
        if(x!='L' || x!='E' || x!='S')  std::cout<<"Casella settata non valida"<<std::endl;
        else    status=x;
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

std::ostream& operator<<(std::ostream& out, const Casella& x);

#endif // CASELLA