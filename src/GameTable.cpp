//DANTE GERETTO

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

}

GameTable::GameTable(){
    genTable(table);
    for(int i = 0; i < 4; i++){
        player_pos[i] = 0;
    }
}


void GameTable::printTable(){

    std::string space_holder;
    std::string line;


    int t{0}, k{13}; //Variabile ausiliaria per gestire l'i dell'array

    for(int j=0; j<9;j++)
    {
        if(j>0)line+=char(j+64);
        if(j==0) line+="   1   2   3   4   5   6   7   8";
        else if(j==1)       //Prima riga
        {
            t=14;
            for(int i=0; i<8;i++)
            {
                line+=" |"+print_casella(table[t])+isPlayer(t)+"|";
                t++;
            }
        }
        else if(j==8)   //Ultima riga 
        {
            t=7;
            for(int i=0; i<8; i++)
            {
                line+=" |"+print_casella(table[t])+isPlayer(t)+"|";
                t--;
            }
        }
        else{
            space_holder="                          ";
            line+=" |"+print_casella(table[k])+isPlayer(k)+"|";
            k--;
            if(isPlayer(t).size()>0 || isBuilt(t).size()>0) //Da modificare ma funziona
            {
                space_holder.resize(space_holder.size()-isPlayer(t).size()-isBuilt(t).size());

            } 
            line+=space_holder+"|"+print_casella(table[t])+isPlayer(t)+"|";
            t++;
            space_holder.clear();
        } 
        std::cout<<line<<std::endl;
        line.clear();
    }
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
void GameTable::print_legenda(int player)
{

    if(player == 0){
        return;
    }

    std::string s="";

    for(int i=0; i<28; i++){
        if(table[i].number_player() == player)
        {
            if(table[i].get_belongings() == 2) s+=" ha una casa in " + conversion_table(i)+",";
            else if(table[i].get_belongings() == 3) s+=" ha un'albergo in " + conversion_table(i)+",";
            else if(table[i].get_belongings() == 1) s+=" ha un terreno in " + conversion_table(i)+",";
        }
    }
    std::cout << "Il player "+ std::to_string(player) + s<<std::endl;
}

std::string conversion_table(int i){
    if (i < 8) return "H"+std::to_string(8-i);// i è nella riga H
    else if (i < 15) return std::string(1, char(79-i))+"1";       
    else if (i < 23) return "A"+std::to_string(i-13);

    else return std::string(1, char(i+44)) + "8";
} 

void print_double(std::string a){
    std::ofstream file("log.txt", std::ios::app);
    if(file.is_open()){
        file << a;
        std::cout << a;
    }
}

