#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <iostream>
#include <string>

using std::string;

class Entidad {

protected:
    string nombre;
    int puntosVida;
    const int vidaMax;
    int x, y;

public:
    Entidad();
    Entidad(string, int, int, int);
    string getName();
    int getHP();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setHP(int);
    virtual void atacar(Entidad*) = 0;
    ~Entidad();
};
#endif //ENTIDAD_H
