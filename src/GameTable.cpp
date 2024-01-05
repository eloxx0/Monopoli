#include "../include/GameTable.h"


Casella* genTable()
{
    Casella table[28];
    int countE{0}, countS{0}, countL{0}, i{0};
    std::srand(std::time(0));
    while(i<28)
    {
        int rnd_status=1+rand()%3;
        if(i%7==0) 
        {
            table[i].set_status(0);
        }
        if(rnd_status==1 && countE<8)
        {
            table[i].set_status('E');
            i++;
            countE++;
            break;
        }
        if(rnd_status==2 && countS<10)
        {
            table[i].set_status('S');
            i++;
            countS++;
            break;
        }
        if(rnd_status==3 && countL<6)
        {
            table[i].set_status('L');
            i++;
            countS++;
            break;
        }

    }

    return table;
}

GameTable::GameTable(){
    this-> table=genTable();
}
