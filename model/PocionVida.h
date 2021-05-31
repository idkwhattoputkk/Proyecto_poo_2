//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONVIDA_H
#define POCIONVIDA_H
#include "Item.h"
#include "entidad.h"
#include "jugador.h"
//clase vida
class PocionVida : public Item
{
private://atributos
    const static int PUNTOSVIDA;
public://metodos
    PocionVida();
    PocionVida(string, int, int, int, int);
    ~PocionVida();
    void usar(Entidad*, Entidad*) override;
    int getHP();
};
#endif //  POCIONVIDA_H