//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef POCIONATAQUE_H
#define POCIONATAQUE_H
//includes
#include "Item.h"

class PocionAtaque : public Item
{
private:
    static const int PUNTOSATAQUE;
public:
    PocionAtaque();
    int getATK();
};
#endif // POCIONATAQUE_H