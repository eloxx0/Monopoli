#include "../include/Player.h"
#include <random>
#include <chrono>

//il tabellone è formato da 28 caselle disposte come ai lati di un quadrato 8x8
//la prima e ultima riga possiedono 8 caselle ciascuna, tutte quelle in mezzo ne possiedono 2
/* std::string string_position(int pos){ */
/* } */

int throw_dice(){
    //imposta come seed del generatore randomico il tempo attuale
    std::srand(std::time(0));
    int a = 1 + (std::rand() % 6);
    int b = 1 + (std::rand() % 6);
    return a+b;
}
