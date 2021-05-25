#ifndef JEFE_H
#define JEFE_H

#include <iostream>
#include "entidad.h"
#include "item.h"
#include "ataque.h"
#include <string>
#include <vector>


using std::string;
using std::vector;

class Jefe : public Entidad{

protected:
    string nombre;
    int puntosVida;
    const int vidaMax;
    int x;
    int y;

private:
    Item recompensa;
    vector<Ataque> listaAtaques;

public:
    Jefe();
    string getName();
    int getHP();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setHP(int);
    Item &getRecompensa();

};
#endif //JEFE_H
