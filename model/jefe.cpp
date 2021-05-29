#include "jefe.h"

Jefe::Jefe(){

}

Jefe::Jefe(string nombre, int puntosVida, int vida, int pos): Entidad(nombre, puntosVida, vida, pos);
{

}

Item Jefe::getRecompensa(){
    return recompensa;
}

void Jefe::atacar(Entidad* enemigo) override{
    srand(time(NULL));
    int posAtaque = rand() % listaAtaques.size();
    Ataque atk = listaAtaques[posAtaque];
    std::cout << getName() << " usa " << atk->getNombre() << std::endl;
    enemigo->setHP( enemigo->getHP() - atk->getPotencia() );
}
