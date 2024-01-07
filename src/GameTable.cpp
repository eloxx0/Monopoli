#include "../include/GameTable.h"
#include "../include/Casella.h"


void genTable(Casella *table)
{
    table[0].set_status('P');
    int countE{0}, countS{0}, countL{0}, i{1};
    std::srand(std::time(0));
    while(i<28)
    {
        int rnd_status=1+rand()%3;
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

}

GameTable::GameTable(){
    genTable(table);
}


void GameTable::printTable(){
    std::string space_holder="|                  |";
    std::string line;
    /*for(int j=0; j<9;j++) //Linee
    {
        if(j>0)line+=char(j+64);
        for(int i=0; i<8; i++) //Colonne
        {
            if(j==0) line+=" "+std::to_string(i+1);
            else if(j==1 || j==8){
               // line+='|'+table[i].get_status()+'|';
               line += std::to_string((j-1)*7+i);
            }
            /*else{
                line+= '|'+ table[(j-1)*7+i].get_status()+'|';
                line+= space_holder + table[(j-1)*7+i++].get_status()+'|';
            }

        }
        std::cout<<line<<std::endl;
        line.clear();
    }*/

    int i{0}, j{0};
    while(i+j<44){
        if(j>0)line+=char(j+64);    //Lettera ad inizio riga
        else
        {
            line+=" "+std::to_string(i+1);
            i++;
        } ;


    }
   
    
}