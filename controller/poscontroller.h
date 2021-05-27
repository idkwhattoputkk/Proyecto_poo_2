#ifdef POS_CONTROLLER_H
#define POS_CONTROLLER_H

#include "../model/mazmorra.h"
#include "../model/entidad.h"
#include "../model/Item.h"

class PosController
{
public:
    PosController();
    void posicionar(Mazmorra*, int, Union*); // <----- Reemplazar el Union
    void mover(Mazmorra*, Entidad*, int);
    void quitar(Mazmorra*, int);
    bool ocupado(Mazmorra*, int);
};

#endif