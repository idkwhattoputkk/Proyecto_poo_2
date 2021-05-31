#include "jefe.h"

Jefe::Jefe() : recompensa(nullptr)
{
    listaAtaques.push_back( Ataque("Rayo Tolerador", 30) );
    listaAtaques.push_back( Ataque("Gas Pimienta", 40) );
    listaAtaques.push_back( Ataque("Rasengan", 50) );
}

Jefe::Jefe(string nombre, int vidaMax, int pos):
Entidad(nombre, vidaMax, pos) {}

Jefe::Jefe(string nombre, int vidaMax, int pos, Item* item): recompensa(item),
Entidad(nombre, vidaMax, pos) {}

void Jefe::turno(Entidad* enemigo)
{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk.getName() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk.getPotencia() );
}

Item* Jefe::soltar()
{
    return recompensa;
}
