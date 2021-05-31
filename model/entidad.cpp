#include "entidad.h"

// Constructor
Entidad::Entidad() {}

Entidad::Entidad(string nombre, int vidaMax, int pos):
    nombre(nombre), vidaMax(vidaMax), pos(pos) 
{
    puntosVida = vidaMax;
}

string Entidad::getName(){
    return this->nombre;
}

int Entidad::getHP(){
    return this->puntosVida;
}

int Entidad::getPos() const{
    return this->pos;
}

void Entidad::setPos(int pos){
    this->pos = pos;
}

void Entidad::setHP(int HP){
    this->puntosVida = HP;
}

int Entidad::getVidaMax() const
{
    return vidaMax;
}

Entidad::~Entidad(){}