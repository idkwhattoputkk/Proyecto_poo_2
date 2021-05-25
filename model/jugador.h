#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "entidad.h"
#include "item.h"
#include <string>
#include <map>


using std::string;
using std::map;
using std::cout;
using std::cin;
using std::pair;

class Jugador : public Entidad{

protected:
    string nombre;
    int puntosVida;
    const int vidaMax;
    int x;
    int y;

private:
    map<int,Item> inventario;
    int puntosATK;

public:
    Jugador();
    string getName();
    int getHP();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setHP(int);
    void mostrarInventario();
    void setATK();
    void usar(int);
    void addInventario(Item*);
    int eliminarItem(int);

};
#endif //JUGADOR_H
