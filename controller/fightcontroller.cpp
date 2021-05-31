#include "fightcontroller.h"

PeleaController::PeleaController(): turnos(0) {}

//Retorna verdadero cuando vences, y falso si mueres
bool PeleaController::batalla(Entidad* jugador, Mazmorra* mazmorra, int pos)
{
    Position* enemigo = mazmorra->getContenido(pos);
    do{
        jugador->turno( enemigo->content );
        this->incrementarTurnos();
        if( enemigo->content->getHP() <= 0 ){
            std::cout << "Venciste!\n";
            Item* recompensa = enemigo->content->soltar();
            if( recompensa != nullptr ){
                Position contenido = {.content = recompensa, .tipo = ITEM};
                mazmorra->quitarContenido( pos );
                mazmorra->setContenido(pos, &contenido);
            } else mazmorra->quitarContenido( pos );
            return true;
        }
        if( jugador->getEscape() == true ) return true;
        
        enemigo->content->turno( jugador );
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