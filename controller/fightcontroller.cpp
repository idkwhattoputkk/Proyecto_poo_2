#include "fightcontroller.h"

PeleaController::PeleaController(): turnos(0) {}

bool PeleaController::batalla(Jugador* jugador, Mazmorra* mazmorra, int pos) //Retorna verdadero cuando vences, y falso si mueres
{
    Position* enemigo = mazmorra->getContenido(pos);
    do{
        jugador->atacar( enemigo );
        this->incrementarTurnos();
        if( enemigo->getHP() <= 0 ){
            std::cout << "Venciste!\n";
            mazmorra->quitarContenido( pos );
            return true;
        }
        enemigo->atacar( jugador );
        if( jugador->getHP() <= 0 ){
            return false;
        }
    } while(true);
}

unsigned int PeleaController::getTurnos() const
{
    return turnos;
}

void PeleaController::incrementarTurnos(unsigned value)
{
    ++turnos;
}