#ifdef TAKE_CONTROLLER_H
#define TAKE_CONTROLLER_H

#include "../model/mazmorra.h"
#include "../model/entidad.h"

class TomarController
{
public:
    TomarController();
    bool mensaje(Mazmorra*, int);
    void addInventario(Mazmorra*, Entidad*, int);
};

#endif