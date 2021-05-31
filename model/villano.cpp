#include "villano.h"

Villano::Villano(){
    listaAtaques.push_back( Ataque("Placaje", 20) );
    listaAtaques.push_back( Ataque("Chidori", 35) );
}

Villano::Villano(string nombre, int vidaMax, int pos): 
    Entidad(nombre, vidaMax, pos) {}

void Villano::turno(Entidad* enemigo)
{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk.getName() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk.getPotencia() );
}

Item* Villano::soltar()
{
    return nullptr;
}

Villano::~Villano() {}