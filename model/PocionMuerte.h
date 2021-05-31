#ifndef POCIONMUERTE_H
#define POCIONMUERTE_H
//includes
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
//clase de pocion de muerte
class PocionMuerte: public Item{
private://atributos
    int numAleatorio;
    static const int MIN, MAX, NUMEXITO;
public://metodos
    PocionMuerte();
    PocionMuerte(string, int, int, int, int);
    bool hacerEfecto();
    void usar(Entidad*, Entidad*) override;
    ~PocionMuerte();
};

#endif // POCIONMUERTE_H
