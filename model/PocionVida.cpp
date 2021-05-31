#include "PocionVida.h"

//Inicializa la variable PI que es estática y constante
const int PocionVida::PUNTOSVIDA = 70;

//constructores y metodos de pocion de vida.
PocionVida::PocionVida() {}

PocionVida::PocionVida(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion) : Item(nombre, durabilidad, desgaste, frecAparicion, 
    frecDesaparicion) {}

int PocionVida::getHP() {
    return this->PUNTOSVIDA;
}

void PocionVida::usar(Entidad* jugador, Entidad* enemigo)
{
    Jugador* player;
    do{
        player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
    }while( true );
    if( jugador->getHP() + PUNTOSVIDA < jugador->getVidaMax() )
        jugador->setHP( jugador->getHP() + PUNTOSVIDA );
    else jugador->setHP( jugador->getVidaMax() );

    player->eliminarItem(pocket);
    delete this;
}

PocionVida::~PocionVida() {}