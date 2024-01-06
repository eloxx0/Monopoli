#include "../include/Casella.h"
#include "../include/Player.h"

Casella::Casella():status{0}, player{nullptr}, number_player{0}, house{false}, hotel{false}{}


std::ostream& operator<<(std::ostream& out, const Casella& x){

    return out<<x.get_status()<<x.get_house()<<x.get_hotel()<<" | "<<std::endl;    
    
}
