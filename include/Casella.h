#ifndef CASELLA
#define CASELLA
#include <iostream>
class Player;

class Casella{

    private:
    
    char status; 
    Player* player;
    int number_player;
    int cost;
    //definire come dei bool, come fossero uno switch
    bool house;
    bool hotel;
    
    public:

    Casella(); //costruttore di default, casella settata come vuota
    //definire getter/setter lusso/eco/standard tramite status
    //setter e getter
    
    Player* get_propriety(void){    //ritorna puntatore a player compilatore non riconosce il tipo player
        return player;
    }

    void set_propriety(Player* p){
        player = p;
    }

    int get_cost() const{
        return cost;
    }
    
    int get_number_p() const{
        return number_player;
    }

    void set_number_p(int a){
        number_player = a;
        return;
    }
    
    char get_status() const{
        return status;
    }
    
    void set_status(char x){
        status=x;
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
