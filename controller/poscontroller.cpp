#include "poscontroller.h"

PosController::PosController() {}

void PosController::posicionar(Mazmorra* mazmorra, int pos, Position* position)
{
    mazmorra->setContenido(pos, position);
}

bool PosController::mover(Mazmorra* mazmorra, Jugador* jugador, int pos)
{   
    if( ocupado(mazmorra, pos) != VACIO ) return false;
    mazmorra->setContenido(pos, jugador);
    mazmorra->quitarContenido( pos );
    jugador->setPos(pos);
    return true;
}

void PosController::quitar(Mazmorra* mazmorra, int pos)
{
    mazmorra->quitarContenido(pos);
}

Tipo PosController::ocupado(Mazmorra* mazmorra, int pos)
{
    return mazmorra->ocupado(pos);
}