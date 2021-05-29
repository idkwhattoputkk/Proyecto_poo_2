#ifdef POS_CONTROLLER_H
#define POS_CONTROLLER_H

#include "../model/mazmorra.h"

class PosController
{
public:
    PosController();
    void posicionar(Mazmorra*, int, Position*);
    bool mover(Mazmorra*, Jugador*, int);
    void quitar(Mazmorra*, int);
    bool ocupado(Mazmorra*, int);
};

#endif