#ifndef VILLANO_H
#define VILLANO_H

#include <iostream>
#include <string>
#include <vector>
#include "entidad.h"
#include "ataque.h"

using std::string;
using std::vector;

class Villano  : public Entidad{

protected:
    string nombre;
    int puntosVida;
    const int vidaMax;
    int x;
    int y;
private:
    vector<Ataque> listaAtaques;
public:
    Villano();
    Villano(string, int, int, int);
    string getName();
    int getHP();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setHP(int);
    ~Villano();

};
#endif //ENTIDAD_H
