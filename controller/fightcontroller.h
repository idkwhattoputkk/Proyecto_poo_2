#ifdef FIGHT_CONTROLLER_H
#define FIGHT_CONTROLLER_H

#include "../model/mazmorra.h"

class PeleaController
{
private:
    unsigned int turnos;
public:
    PeleaController();
    bool batalla(Jugador*, Mazmorra*, int);
    unsigned int getTurnos() const;
    void incrementarTurnos(unsigned);
};

#endif