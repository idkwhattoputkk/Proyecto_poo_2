#include "PocionAtaque.h"

const int PocionAtaque::PUNTOSATAQUE = 90;

PocionAtaque::PocionAtaque() {}

PocionAtaque::PocionAtaque(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion) : Item(nombre, durabilidad, desgaste, frecAparicion, frecDesaparicion) {}

int PocionAtaque::getATK() {
    return this->PUNTOSATAQUE;
}

void PocionAtaque::usar(Entidad* jugador, Entidad* enemigo)
{
    Jugador* player;
    enemigo->setHP( enemigo->getHP() - PUNTOSATAQUE);
    do{
         player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
    }while( true );
    player->eliminarItem(pocket);
    delete this;
}

PocionAtaque::~PocionAtaque() {}
