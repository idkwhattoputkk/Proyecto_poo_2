//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef POCIONMUERTE_H
#define POCIONMUERTE_H
//includes
#include "model/Item.h"
class PocionMuerte: public Item{
private:
    int numAleatorio;
    static const int MIN, MAX, NUMEXITO;
public:
    PocionMuerte();
    bool hacerEfecto();
    // ~PocionMuerte();
};

#endif // POCIONMUERTE_H
