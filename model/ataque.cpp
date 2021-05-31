#include "ataque.h"

Ataque::Ataque(){}

Ataque::Ataque(string nombre, int potencia): nombre(nombre),
    potencia(potencia) {}

string Ataque::getName(){
    return this->nombre;
}

int Ataque::getPotencia(){
    return this->potencia;
}

Ataque::~Ataque(){}