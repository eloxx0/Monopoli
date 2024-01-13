// DANTE GERETTO

#include "../include/GameTable.h"
#include "../include/Casella.h"

void genTable(Casella *table)
{
    table[0].set_status('P');
    int countE{0}, countS{0}, countL{0}, i{1};
    std::srand(std::time(0));
    while (i < 28)
    {
        int rnd_status = 1 + std::rand() / ((RAND_MAX + 1u) / 3);
        if (i % 7 == 0)
        {
            table[i].set_status(' ');
            i++;
        }
        if (rnd_status == 1 && countE < 8)
        {
            table[i].set_status('E');
            i++;
            countE++;
        }
        else if (rnd_status == 2 && countS < 10)
        {
            table[i].set_status('S');
            i++;
            countS++;
        }
        else if (rnd_status == 3 && countL < 6)
        {
            table[i].set_status('L');
            i++;
            countS++;
        }
    }
}

GameTable::GameTable()
{
    genTable(table);
    for (int i = 0; i < 4; i++)
    {
        player_pos[i] = 0;
    }
}

void GameTable::printTable()
{
    int space{0};
    std::string space_holder;
    std::string line;
    line = "   1";
    for (int i = 1; i < 8; i++)
        line += "          " + std::to_string(i + 1);
    std::cout << line << std::endl;
    line.clear();

    for (int j = 0; j < 8; j++)
    {
        line = std::string(1, j + 65);

        if (j == 0)
        {
            for (int i = 14; i <= 21; i++)
            {
                space = 7 - (isPlayer(i).size() + isBuilt(i).size());
                space_holder = std::string(space, ' ');
                line += " |" + print_casella(table[i]) + isPlayer(i) + "|" + space_holder;
            }
            space_holder.clear();
        }
        else if (j == 7)
        {
            for (int i = 7; i >= 0; i--)
            {
                space = 7 - (isPlayer(i).size() + isBuilt(i).size());
                space_holder = std::string(space, ' ');
                line += " |" + print_casella(table[i]) + isPlayer(i) + "|" + space_holder;
            }
            space_holder.clear();
        }
        else
        {
            space = 74 - (isPlayer(14 - j).size() + isBuilt(14 - j).size());
            space_holder = std::string(space, ' ');
            line += " |" + print_casella(table[14 - j]) + isPlayer(14 - j) + "|" + space_holder + "|" + print_casella(table[21 + j]) + isPlayer(21 + j) + "|";
            space_holder.clear();
        }
        std::cout << line << std::endl;
    }

}

std::string GameTable::isPlayer(int pos)
{
    std::string p = "";
    for (int i = 0; i < 4; i++)
    {
        // controlla anche che il giocatore non sia stato eliminato, cioè quando la sua posizione
        // viene settata a -1
        if (player_pos[i] == pos && player_pos[i] != -1)
            p += std::to_string(i + 1);
    }
    return p;
}

std::string GameTable::isBuilt(int pos)
{
    if (table[pos].get_belongings() == 3)
        return "^";
    else if (table[pos].get_belongings() == 2)
        return "*";
    return "";
}

// stampa i possedimenti del player tramite il numero identificativo del player
void GameTable::print_legenda(int player)
{

    if (player == 0)
    {
        return;
    }

    std::string s = "";

    for (int i = 0; i < 28; i++)
    {
        if (table[i].number_player() == player)
        {
            if (table[i].get_belongings() == 2)
                s += " ha una casa in " + conversion_table(i) + ",";
            else if (table[i].get_belongings() == 3)
                s += " ha un albergo in " + conversion_table(i) + ",";
            else if (table[i].get_belongings() == 1)
                s += " ha un terreno in " + conversion_table(i) + ",";
        }
    }
    std::cout << "Il player " + std::to_string(player) + s << std::endl;
}

std::string conversion_table(int i)
{
    if (i < 8)
        return "H" + std::to_string(8 - i); // i è nella riga H
    else if (i < 15)
        return std::string(1, char(79 - i)) + "1";
    else if (i < 23)
        return "A" + std::to_string(i - 13);

    else
        return std::string(1, char(i + 44)) + "8";
}

void print_double(std::string a)
{
    std::ofstream file("log.txt", std::ios::app);
    if (file.is_open())
    {
        file << a;
    }
    std::cout << a;
}
