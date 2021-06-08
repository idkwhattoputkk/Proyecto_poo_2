#ifndef JUGADOR_H
#define JUGADOR_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include "entidad.h"
#include "Item.h"

using std::string;
using std::unordered_map;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

class Jugador : public Entidad
{
private:
    unordered_map<int,Item*> inventario;
    int puntosATK;
    int numItems;
    bool escape;
    static const int bolsillos;

public:
    Jugador();
    Jugador(string, int, int);
    int getNumItems() const;
    bool getEscape() const;
    void setEscape(bool);
    void mostrarInventario();
    int getATK() const;
    void setATK(int);
    Item* consultar(int);
    void addInventario(Item*);
    void eliminarItem(int);
    void turno(Entidad*) override;
    Item* soltar() override;
    bool escapar();
};
#endif //JUGADOR_H
