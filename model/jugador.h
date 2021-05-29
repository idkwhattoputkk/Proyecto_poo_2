#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "entidad.h"
#include "item.h"
#include <string>
#include <unorderded_map>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::pair;

class Jugador : public Entidad
{
private:
    unordered_map<int,Item*> inventario;
    int puntosATK;
    int numItems;
    static const int bolsillos;

public:
    Jugador();
    Jugador(string, int, int, int);
    int getNumItems() const;
    void mostrarInventario();
    void setATK();
    //void usar(int, Entidad*);
    void addInventario(Item*);
    int eliminarItem(int);
};
#endif //JUGADOR_H
