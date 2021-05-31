#include "PocionAtaque.h"

PocionAtaque::PocionAtaque() {}

PocionAtaque::PocionAtaque(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion, int puntosATK) :
    PUNTOSATAQUE(puntosATK), Item(nombre, durabilidad, desgaste, 
    frecAparicion, frecDesaparicion) {}

int PocionAtaque::getATK() {
    return this->PUNTOSATAQUE;
}

void PocionAtaque::usar(Entidad* jugador, Entidad* enemigo) override
{
    enemigo->setHP( enemigo->getHP() - PUNTOSATAQUE);
    jugador->eliminarItem(pocket);
    ~PocionAtaque();
}

PocionAtaque::~PocionAtaque() {}
