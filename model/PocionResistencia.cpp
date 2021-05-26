#include "model/PocionResistencia.h"
//Constructores y metodos de la clase pocion de resistencia
PocionResistencia::PocionResistencia()
{
    
}

PocionResistencia::PocionResistencia(int puntosResistencia)
{
    this->puntosResistencia = puntosResistencia;
}

PocionResistencia::~PocionResistencia()
{
    
}

int PocionResistencia::getRP() {
    return this->puntosResistencia;
}
