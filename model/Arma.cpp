
#include "model/arma.h"


Arma::Arma(){}
Arma::Arma(int potencia)
{
    this->potencia = potencia;
}
int Arma::getPotencia() {
    return this->potencia;
}

