#ifndef POCIONESCAPE_H
#define POCIONESCAPE_H
//includes
#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
//Clase pocion escape
class PocionEscape: public Item
{
private: // atributos
    int numAleatorio;
    static const int NUMEXITO, MAX, MIN;
public: //metodos
    PocionEscape();
    //Nombre, durabilidad, desgaste, frecAparicion, frecDesaparicion
    PocionEscape(string, int, int, int, int);
    ~PocionEscape();
    void usar(Entidad*, Entidad*) override;
    bool hacerEfecto();
};
#endif