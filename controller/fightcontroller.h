#ifndef FIGHT_CONTROLLER_H
#define FIGHT_CONTROLLER_H

#include "../model/mazmorra.h"
#include "../model/entidad.h"

class PeleaController
{
private:
    unsigned int turnos;
public:
    PeleaController();
    bool batalla(Entidad*, Mazmorra*, int);
    unsigned int getTurnos() const;
    void incrementarTurnos();
};

#endif