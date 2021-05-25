#include "ataque.h"

Ataque::Ataque(){}

Ataque::Ataque(string nombre, int potencia){
    this->nombre = nombre;
    this->potencia = potencia;
}

string Ataque::getName(){
    return this->nombre;
}

int Ataque::getPotencia(){
    return this->potencia;
}

~Ataque(){}