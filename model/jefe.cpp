#include "jefe.h"

Jefe::Jefe() : recompensa(nullptr)
{
    listaAtaques.push_back( Ataque("Rayo Tolerador", foo) );
    listaAtaques.push_back( Ataque("Gas Pimienta", foo) );
    listaAtaques.push_back( Ataque("Rasengan", foo) );
}

Jefe::Jefe(string nombre, int vidaMax, int pos):
Entidad(nombre, vidaMax, pos) {}

Jefe::Jefe(string nombre, int vidaMax, int pos, Item* item): recompensa(item)
Entidad(nombre, vidaMax, pos) {}

void Jefe::turno(Entidad* enemigo) override
{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk.getNombre() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk.getPotencia() );
}

Item* Jefe::soltar() override
{
    return recompensa;
}
