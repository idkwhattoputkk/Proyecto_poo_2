#ifndef POS_CONTROLLER_H
#define POS_CONTROLLER_H

#include "../model/jugador.h"
#include "../model/mazmorra.h"

class PosController
{
public:
    PosController();
    void posicionar(Mazmorra*, int, Position*);
    Tipo mover(Mazmorra*, Jugador*, int);
    void quitar(Mazmorra*, int);
    Tipo ocupado(Mazmorra*, int);
};

#endif