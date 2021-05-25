//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONRESISTENCIA_H
#define POCIONRESISTENCIA_H
#include "model/Item.h"
class PocionResistencia : public Item
{
private: //Atributos
    int puntosResistencia;
public: //metodos
    PocionResistencia();
    int getRP();
};


#endif