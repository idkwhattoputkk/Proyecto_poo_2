
#include "entidad.h"

// Constructor
Entidad::Entidad() {}

Entidad::Entidad(string nombre, int puntosVida, int x, int y){
    this->nombre = nombre;
    this->puntosVida = puntosVida;
    this->x = x;
    this->y = y;
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
Entidad::~Entidad(){}