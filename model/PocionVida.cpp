#include "model/PocionVida.h"

//Inicializa la variable PI que es estática y constante
const int PocionVida::PUNTOSVIDA = 10;

//constructores y metodos de pocion de vida.
PocionVida::PocionVida()
{
    
}

PocionVida::~PocionVida()
{
    
}

int PocionVida::getHP() {
    return this->PUNTOSVIDA;
}
