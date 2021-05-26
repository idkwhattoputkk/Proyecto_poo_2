//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONRESISTENCIA_H
#define POCIONRESISTENCIA_H
//includes
#include "model/Item.h"

//clase pocion de resistencia
class PocionResistencia : public Item
{
private: //Atributos
    int puntosResistencia;
public: //metodos
    PocionResistencia();
    PocionResistencia(int);
    ~PocionResistencia();
    int getRP();
};


#endif