#include "villano.h"

Villano::Villano(){
    listaAtaques.push_back( Ataque("Placaje", foo) );
    listaAtaques.push_back( Ataque("Chidori", foo) );
}

Villano::Villano(string nombre, int vidaMax, int pos): 
    Entidad(nombre, vidaMax, pos) {}

void Villano::turno(Entidad* enemigo) override
{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk.getNombre() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk.getPotencia() );
}

Item* Villano::soltar() override
{
    return nullptr;
}

Villano::~Villano() {}