#include "villano.h"

Villano::Villano() {}

Villano::Villano(string nombre, int puntosVida, int vida, int pos): Entidad(nombre, puntosVida, vida, pos);
{

}

void Villano::Villano(Entidad* enemigo) override{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk->getNombre() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk->getPotencia() );
}

Villano::~Villano() {}