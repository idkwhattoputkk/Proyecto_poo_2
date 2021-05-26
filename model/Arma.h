//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef ARMA_H
#define ARMA_H
//includes
#include "model/Item.h"

//Clase arma
class Arma : public Item{
private: //atributos
    static const int POTENCIA;
public: //metodos
    Arma();
    Arma(int);
    int getPotencia();

};

#endif //ARMA_H