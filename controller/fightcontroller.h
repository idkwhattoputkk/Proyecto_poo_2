#ifdef FIGHT_CONTROLLER_H
#define FIGHT_CONTROLLER_H

#include "../model/mazmorra.h"
#include "../model/entidad.h"

class PeleaController
{
public:
    PeleaController();
    bool batalla(Entidad*, Mazmorra*, int);
};

#endif