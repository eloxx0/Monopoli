#include "../include/Casella.h"

Casella::Casella():status{0}, player{nullptr}, house{false}, hotel{false}{}


std::ostream& operator<<(std::ostream& out, const Casella& x){//sistemare

    return out<<x.get_house()<<x.get_hotel();   
    
}