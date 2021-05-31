#include "model/arma.h"
//Metodos y constructores clase arma
Arma::Arma(){}

Arma::Arma(string nombre, int durabilidad, int desgaste, int frecAparicion
    int frecDesaparicion, int potencia) : 
    POTENCIA(potencia), Item(nombre, durabilidad, desgaste, frecAparicion
    frecDesaparicion) {}

int Arma::getPotencia() {
    return this->POTENCIA;
}

void Arma::usar(Entidad* jugador, Entidad* enemigo) override
{
    int puntosATK = jugador.getATK() + POTENCIA;
    enemigo->setHP( enemigo->getHP() - puntosATK );
    usos -= desgaste;
    if( usos <= 0 ){
        jugador->eliminarItem(pocket);
        ~Arma();
    }
}

Arma::~Arma() override {}