#ifndef JEFE_H
#define JEFE_H

#include <iostream>
#include "entidad.h"
#include "item.h"
#include "ataque.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using std::string;
using std::vector;

class Jefe : public Entidad{
private:
    Item recompensa;
    vector<Ataque> listaAtaques;

public:
    Jefe();
    Jefe(string, int, int, int);
    Item getRecompensa();
};
#endif //JEFE_H
