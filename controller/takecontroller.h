#ifndef TAKE_CONTROLLER_H
#define TAKE_CONTROLLER_H

#include "../model/mazmorra.h"
#include "../model/entidad.h"
#include "../model/jugador.h"

class TomarController
{
public:
    TomarController();
    bool mensaje(Mazmorra*, int);
    bool addInventario(Mazmorra*, Jugador*, int);
};

#endif