//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef POCIONMUERTE_H
#define POCIONMUERTE_H
//includes
#include "model/Item.h"
#include <cstdlib>
#include <ctime>
//clase de pocion de muerte
class PocionMuerte: public Item{
private://atributos
    int numAleatorio;
    static const int MIN, MAX, NUMEXITO;
public://metodos
    PocionMuerte();
    bool hacerEfecto();
    ~PocionMuerte();
};

#endif // POCIONMUERTE_H
