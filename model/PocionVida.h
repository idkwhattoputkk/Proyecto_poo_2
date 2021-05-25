//
// Created by Emanuel Umaña on 25/05/21.
//
#ifndef POCIONVIDA_H
#define POCIONVIDA_H
#include "model/Item.h"
class PocionVida : public Item
{
private:
    static const int PUNTOSVIDA;
public:
    PocionVida();
    // ~PocionVida() {}
    int getHP();
};
#endif //  POCIONVIDA_H