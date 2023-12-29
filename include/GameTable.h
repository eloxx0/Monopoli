#ifndef GAMETABLE_H
#define GAMETABLE_H

#include "Casella.h"

class GameTable{

    public:
    //array di caselle? pubblico o privato? deve essere possibile modificarlo e accederci liberamente..
    
    Casella table[27];

    //tabellone di gioco. Viene creato un array di 28 caselle. Le caselle di indice 0,
    //7, 14, 21 sono caselle ANGOLARI, le altre LATERALI
    //il tabellone deve gestire la creazione delle caselle, di cui devono essere:
    //8 caselle economiche, 10 caselle standard e 6 caselle di lusso, disposte
    //CASUALMENTE in posizione laterale
    //La casella di indice 0 nell'array è la casella di start, e corrispone alla coordinata
    //1A. E' necessario creare un metodo che converta l'indice della casella in coordinate
    //per gestire la stampa
    GameTable();

    //vari metodi di stampa, di modifica del tabellone



};

#endif //GAMETABLE_H
