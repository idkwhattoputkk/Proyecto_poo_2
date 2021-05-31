#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <iostream>
#include <string>

using std::string;

class Entidad {

protected:
    string nombre;
    int puntosVida;
    int vidaMax;
    int pos;

public:
    Entidad();
    Entidad(string, int, int);
    string getName();
    int getHP();
    int getPos() const;
    void setPos(int);
    void setHP(int);
    int getVidaMax() const;
    virtual void turno(Entidad*) = 0;
    virtual Item* soltar() = 0;
    ~Entidad();
};
#endif //ENTIDAD_H
