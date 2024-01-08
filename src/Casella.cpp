#include "../include/Casella.h"
#include "../include/Player.h"

Casella::Casella():status{0}, player{nullptr}, belongings{0}{}

int Casella::number_player(){

    //se il puntatore non è nullptr, entra nell'if e ritorna il numero del giocatore
    if(get_propriety()){
        return get_propriety() -> get_player();
    }
    
    //se non è posseduta da nessuno, ritorna 0
    return 0;
}

int Casella::get_cost(){
    
    if(get_status()=='L'){
    
        if(get_belongings()==0){
        
            //Prezzo per acquistare il terreno
            return 20;
        
        }
        
        else if(get_belongings()==1){
        
            //Prezzo per acquistare una casa
            return 10;
        
        }
        
        else if(get_belongings()==2){
        
            //Prezzo per miglioramento ad albergo
            return 10;
            
        }        
        
        else if(get_belongings()==3){
        
            //Non si può ulteriormente comprare
            return 0;
        
        }
    
    }
    
    else if(get_status()=='S'){
    
        if(get_belongings()==0){
        
            //Prezzo per acquistare il terreno
            return 10;
        
        }
        
        else if(get_belongings()==1){
        
            //Prezzo per acquistare una casa
            return 5;
        
        }
        
        else if(get_belongings()==2){
        
            //Prezzo per miglioramento ad albergo
            return 5;
            
        }        
        
        else if(get_belongings()==3){
        
            //Non si può ulteriormente comprare
            return 0;
        
        }
    
    }
        
    else if(get_status()=='E'){
    
        if(get_belongings()==0){
        
            //Prezzo per acquistare il terreno
            return 6;
        
        }
        
        else if(get_belongings()==1){
        
            //Prezzo per acquistare una casa
            return 3;
        
        }
        
        else if(get_belongings()==2){
        
            //Prezzo per miglioramento ad albergo
            return 3;
            
        }        
        
        else if(get_belongings()==3){
        
            //Non si può ulteriormente comprare
            return 0;
        
        }
    
    }
    
    return 0;
    
}

int Casella::get_price(){

    if(get_belongings()==2){    //pernottamento in casa
    
        if(get_status()=='L') return 7;
    
        else if(get_status()=='S') return 4;
        
        else if(get_status()=='E') return 2;
    
    }
    else if(get_belongings()==3){   //pernottamento in albergo
    
        if(get_status()=='L') return 14;
    
        else if(get_status()=='S') return 8;
        
        else if(get_status()=='E') return 4;
    
    }
    //se non sono presenti case o alberghi, ritorna 0
    return 0;
}

int Casella::player_buyable(int player){

    if(get_belongings() == 0) return 1;
    
    else if(number_player() == player && get_belongings() == 1) return 2;

    else if(number_player() == player && get_belongings() == 2) return 3;

    else return 0;

}

std::ostream& operator<<(std::ostream& out, const Casella& x){

    return out<<x.get_status()<<x.get_belongings()<<" | "<<std::endl;    
    
}
