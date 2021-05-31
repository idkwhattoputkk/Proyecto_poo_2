#include "fightcontroller.h"

PeleaController::PeleaController(): turnos(0) {}

//Retorna verdadero cuando vences, y falso si mueres
bool PeleaController::batalla(Entidad* jugador, Mazmorra* mazmorra, int pos)
{
    Position* enemigo = mazmorra->getContenido(pos);
    do{
        Jugador* player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
        jugador->turno( enemigo->contenido.entidad );
        this->incrementarTurnos();
        if( enemigo->contenido.entidad->getHP() <= 0 ){
            std::cout << "Venciste!\n";
            Item* recompensa = enemigo->contenido.entidad->soltar();
            if( recompensa != nullptr ){
                Position p = {.tipo=ITEM};
                p.contenido.item = recompensa;
                mazmorra->quitarContenido( pos );
                mazmorra->setContenido(pos, &p);
            } else mazmorra->quitarContenido( pos );
            return true;
        }
        if( player->getEscape() == true ) return true;
        
        enemigo->contenido.entidad->turno( jugador );
        if( jugador->getHP() <= 0 ){
            return false;
        }
    } while(true);
}

unsigned int PeleaController::getTurnos() const
{
    return turnos;
}

void PeleaController::incrementarTurnos()
{
    ++turnos;
}