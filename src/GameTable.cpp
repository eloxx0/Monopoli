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
    int i=0;
    while(i<28)
    {
        line += char(i+65);
        if(i<8 || i>22)
        {
            line+='|'+table[i].get_status()+'|';
        }
        else if(i>=8)
        {
            line+='|'+table[i].get_status();
            line+=space_holder+table[++i].get_status();    
        }
        line="";
        i++;
    }
}