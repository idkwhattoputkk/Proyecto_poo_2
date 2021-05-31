#ifndef JEFE_H
#define JEFE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "ataque.h"
#include "entidad.h"
#include "item.h"

using std::string;
using std::vector;

class Jefe : public Entidad{
private:
    Item* recompensa;
    vector<Ataque> listaAtaques;

public:
    Jefe();
    Jefe(string, int, int);
    Jefe(string, int, int, Item*);
    Item* soltar() override;
    void atacar(Entidad*) override;
};
#endif //JEFE_H