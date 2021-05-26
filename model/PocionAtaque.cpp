#include "PocionAtaque.h"
//constante daño de ataque
const int  PocionAtaque::PUNTOSATAQUE= 15;
PocionAtaque::PocionAtaque()
{
    
}

int PocionAtaque::getATK() {
    return this->PUNTOSATAQUE;
}

PocionAtaque::~PocionAtaque()
{
    
}
