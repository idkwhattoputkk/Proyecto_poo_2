
#include "model/arma.h"
//Variable constante y estatica que refleja el valor de arma
const int Arma::POTENCIA  = 50;

//Metodos y constructores clase arma
Arma::Arma(){}

int Arma::getPotencia() {
    return this->POTENCIA;
}

