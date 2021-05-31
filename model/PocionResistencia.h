//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONRESISTENCIA_H
#define POCIONRESISTENCIA_H
//includes
#include "../model/Item.h"

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