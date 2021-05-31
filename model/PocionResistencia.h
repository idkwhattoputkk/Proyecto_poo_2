//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONRESISTENCIA_H
#define POCIONRESISTENCIA_H
//includes
#include "Item.h"
#include "entidad.h"
#include "jugador.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//clase pocion de resistencia
class PocionResistencia : public Item
{
private: //Atributos
    const int puntosResistencia;
public: //metodos
    PocionResistencia();
    PocionResistencia(string,int,int,int,int,int);
    int getRP();
    void usar(Entidad*,Entidad*) override;
    ~PocionResistencia();
};


#endif