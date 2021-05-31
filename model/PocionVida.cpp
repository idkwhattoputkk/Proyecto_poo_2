#include "PocionVida.h"

//Inicializa la variable PI que es estática y constante
const int PocionVida::PUNTOSVIDA = 10;

//constructores y metodos de pocion de vida.
PocionVida::PocionVida() {}

PocionVida::PocionVida(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion, int puntosVida) :
    PUNTOSVIDA(puntosVida), Item(nombre, durabilidad, desgaste, frecAparicion, 
    frecDesaparicion) {}

int PocionVida::getHP() {
    return this->PUNTOSVIDA;
}

void usar(Entidad* jugador, Entidad* enemigo) override
{
    if( jugador->getHP() + PUNTOSVIDA < jugador->getVidaMax() )
        jugador->setHP( jugador->getHP() + PUNTOSVIDA );
    else jugador->setHP( jugador->getVidaMax() );

    jugador->eliminarItem(pocket);
    ~PocionVida();
}

PocionVida::~PocionVida() {}