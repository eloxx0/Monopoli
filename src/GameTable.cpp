#include "../include/GameTable.h"
#include "../include/Casella.h"


void genTable(Casella *table)
{
    table[0].set_status('P');
    int countE{0}, countS{0}, countL{0}, i{1};
    std::srand(std::time(0));
    while(i<28)
    {
        int rnd_status=1 + std::rand() / ((RAND_MAX + 1u) / 3);
        if(i%7==0) 
        {
            table[i].set_status(' ');
            i++;
        }
        if(rnd_status==1 && countE<8)
        {
            table[i].set_status('E');
            i++;
            countE++;
        }
        else if(rnd_status==2 && countS<10)
        {
            table[i].set_status('S');
            i++;
            countS++;
        }
        else if(rnd_status==3 && countL<6)
        {
            table[i].set_status('L');
            i++;
            countS++;
        }

    }

    /*i=0;
    while(i<28){
        std::cout<<i<<table[i].get_status()<<" ";
        i++;
    }
    std::cout<<"\n";*/

}

GameTable::GameTable(){
    genTable(table);
    gen_filelog();
    for(int i = 0; i < 4; i++){
        player_pos[i] = 0;
    }
}


void GameTable::printTable(){

    std::string space_holder;
    std::string line;


    int t{0}, k{13}; //Variabile ausiliaria per gestire l'indice dell'array

    for(int j=0; j<9;j++)
    {
        if(j>0)line+=char(j+64);
        if(j==0) line+="   1   2   3   4   5   6   7   8";
        else if(j==1)
        {
            t=14;
            for(int i=0; i<8;i++)
            {
                line+=" |"+print_casella(table[t])+isPlayer(t)+"|";
                t++;
            }
        }
        else if(j==8)
        {
            t=7;
            for(int i=0; i<8; i++)
            {
                line+=" |"+print_casella(table[t])+isPlayer(t)+"|";
                t--;
            }
        }
        else{
            space_holder="                         ";
            line+=" |"+print_casella(table[k])+isPlayer(t)+"|";
            k--;
            if(isPlayer(t).size()>0 || isBuilt(t).size()>0) //Da modificare ma funziona
            {
                space_holder.resize(space_holder.size()-isPlayer(t).size()-isBuilt(t).size());
                space_holder.shrink_to_fit();
                //std::cout<<space_holder.size();
            } 
            /* line+=space_holder+"|"+std::string(1,table[t].get_status())+isPlayer(t)+"|"; */
            line+=space_holder+"|"+print_casella(table[t])+isPlayer(t)+"|";
            t++;
        } 
        std::cout<<line<<std::endl;
        line.clear();
    }
    /*for(int j=0; j<9;j++) //Linee
    {
        if(j>0)line+=char(j+64); //Carattere ad inzio riga

        if(j==0) line+="   1   2   3   4   5   6   7   8"; //Riga di numeri
        else if(j==1 || j==8)
        {
            for(int i=0; i<8;i++){           
               line+=" |"+std::string(1, table[t].get_status())+isPlayer(t)+"|"; //Riga con il centro pieno
               t--;
            }
        }
        else //Riga con il centro vuoto
        {
            space_holder="                         ";
            line+=" |"+std::string(1, table[t].get_status())+isPlayer(t)+"|";
            if(isPlayer(t).size()>0)
            {
                space_holder.resize(space_holder.size()-isPlayer(t).size());
                space_holder.shrink_to_fit();
                //std::cout<<space_holder.size();
            } 
            t--;
            line+=space_holder+"|"+std::string(1,table[t].get_status())+isPlayer(t)+"|";
            t--;
        } 
        std::cout<<line<<std::endl;
        line.clear();
        space_holder.clear();
    } */
    
}

std::string GameTable::isPlayer(int pos)
{
    std::string p="";
    for(int i=0; i<4; i++)
    {
        //controlla anche che il giocatore non sia stato eliminato, cioè quando la sua posizione
        //viene settata a -1
        if(player_pos[i]==pos && player_pos[i] != -1) p+=std::to_string(i+1);
    }
    return p;
}

std::string GameTable::isBuilt(int pos)
{
    if(table[pos].get_belongings() == 3) return "^";
    else if(table[pos].get_belongings() == 2) return "*";
    return "";
}

//stampa i possedimenti del player tramite il numero identificativo del player
//FINIRE QUESTI METODI
std::string GameTable::print_legenda(int player){

std::string s="";

    for(int i=0; i<28; i++){
    
        if(table[i].get_belongings()==2) s+=" possiede una casa nella casella "+ std::to_string(i)+", ";
        else if(table[i].get_belongings()==3) s+= " possiede un'albergo nella casella "+ std::to_string(i)+", ";
    //sistemare
    }
    
std::string x="Il giocatore "+ player + s;  
  
    return x;
}

std::string GameTable::conversion_table(){return "da fare";} //che argomento metto converte in coordinate 

//creare un file log
void gen_filelog(){

    std::ofstream("Log.txt"); //generazione file

}
