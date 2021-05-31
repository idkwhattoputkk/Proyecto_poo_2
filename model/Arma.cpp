#include "Arma.h"
//Metodos y constructores clase arma
Arma::Arma(): POTENCIA(0) {}

Arma::Arma(string nombre, int durabilidad, int desgaste, int frecAparicion,
    int frecDesaparicion, int potencia) : 
    Item(nombre, durabilidad, desgaste, frecAparicion, frecDesaparicion),
    POTENCIA(potencia) {}

int Arma::getPotencia() {
    return this->POTENCIA;
}

void Arma::usar(Entidad* jugador, Entidad* enemigo)
{
    Jugador* player;
    do{
        player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
        else break;
    } while(true);
    
    int puntosATK = player->getATK() + POTENCIA;
    enemigo->setHP( enemigo->getHP() - puntosATK );
    usos -= desgaste;
    if( usos <= 0 ){
        player->eliminarItem(pocket);
        delete this;
    }
}

Arma::~Arma() {}