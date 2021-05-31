#include "poscontroller.h"

PosController::PosController() {}

void PosController::posicionar(Mazmorra* mazmorra, int pos, Position* position)
{
    mazmorra->setContenido(pos, position);
}

Tipo PosController::mover(Mazmorra* mazmorra, Jugador* jugador, int pos)
{   
    Tipo tipo = ocupado(mazmorra, pos);
    if( tipo != VACIO ) return tipo;
    Position p = {.tipo = ENTIDAD};
    p.contenido.entidad = jugador;
    mazmorra->setContenido(pos, &p);
    mazmorra->quitarContenido( pos );
    jugador->setPos(pos);
    return tipo;
}

void PosController::quitar(Mazmorra* mazmorra, int pos)
{
    mazmorra->quitarContenido(pos);
}

Tipo PosController::ocupado(Mazmorra* mazmorra, int pos)
{
    return mazmorra->ocupado(pos);
}