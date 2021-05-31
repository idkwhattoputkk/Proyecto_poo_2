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
    //Nombre,durabilidad,Desgaste,frecAparicion,frecDesaparicion,PUNTOSATAQUE
    PocionAtaque(string, int, int, int, int, int);
    int getATK();
    void usar(Entidad*, Entidad*) override;
    ~PocionAtaque();
};
#endif // POCIONATAQUE_H