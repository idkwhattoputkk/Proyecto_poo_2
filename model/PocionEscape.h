//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef POCIONESCAPE_H
#define POCIONESCAPE_H
//includes
#include "Item.h"
//Clase pocion escape
class PocionEscape: public Item
{
private: // atributos
    int numAleatorio;
    static const int NUMEXITO, MAX, MIN;
public: //metodos
    PocionEscape();
    bool hacerEfecto();
};



#endif