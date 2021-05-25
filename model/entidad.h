#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::iterator;
using std::pair;

class Entidad {

protected:
    string nombre;
    int puntosVida;
    const int vidaMax;
    int x;
    int y;
public:
    Entidad();
    Entidad(string, int, int, int);
    string getName();
    int getHP();
    int getX();
    int getY;
    void setX(int);
    void setY(int);
    void setHP(int);
    ~Entidad();

};
#endif //ENTIDAD_H
