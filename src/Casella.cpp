#include "../include/Casella.h"
#include "../include/Player.h"

Casella::Casella():status{0}, player{nullptr}, house{false}, hotel{false}{}

int Casella::number_player(){
    //se il puntatore non è nullptr, entra nell'if e ritorna il numero del giocatore
    if(get_propriety()){
        return get_propriety() -> get_player();
    }
    //se non è posseduta da nessuno, ritorna 0
    return 0;
}

int Casella::get_cost(){
    return 1;
}

int Casella::get_price(){
    return 4;
}

std::ostream& operator<<(std::ostream& out, const Casella& x){

    return out<<x.get_status()<<x.get_house()<<x.get_hotel()<<" | "<<std::endl;    
    
}
