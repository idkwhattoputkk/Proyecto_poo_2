#ifndef VILLANO_H
#define VILLANO_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "entidad.h"
#include "ataque.h"

using std::string;
using std::vector;

class Villano  : public Entidad{
private:
    vector<Ataque> listaAtaques;
public:
    Villano();
    Villano(string, int, int);
    void turno(Entidad*) override;
    Item* soltar() override;
    ~Villano();
};
#endif //ENTIDAD_H
