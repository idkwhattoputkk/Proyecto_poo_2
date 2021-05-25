
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

int Entidad::getX(){
    return this->x;
}

int Entidad::getY{
    return this->y;
}

void Entidad::setX(int x){
    this->x = x;
}

void Entidad::setY(int y){
    this->y = y;
}

void Entidad::setHP(int HP){
    this->puntosVida = HP;
}
Entidad::~Entidad(){}