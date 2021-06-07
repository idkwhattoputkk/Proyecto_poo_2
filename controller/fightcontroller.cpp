#include "fightcontroller.h"

PeleaController::PeleaController(): turnos(0) {}

//Retorna verdadero cuando vences, y falso si mueres
int PeleaController::batalla(Entidad* jugador, Mazmorra* mazmorra, int pos)
{
    std::cout << "BATALLA!\n";
    Position* enemigo = mazmorra->getContenido(pos);
    std:: cout << "Contra: " << enemigo->contenido.entidad->getName() << std::endl;
    do{
        Jugador* player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
        jugador->turno( enemigo->contenido.entidad );
        this->incrementarTurnos();
        if( enemigo->contenido.entidad->getHP() <= 0 ){
            std::cout << "\n\nVenciste!\n\n";
            Item* recompensa = enemigo->contenido.entidad->soltar();
            if( recompensa != nullptr ){
                Position p = {.tipo=ITEM};
                p.contenido.item = recompensa;
                mazmorra->quitarContenido( pos );
                mazmorra->setContenido(pos, &p);
            } else mazmorra->quitarContenido( pos );
            return 2;
        }
        if (player->getEscape() == true) {
            return 1;
        }
        
        enemigo->contenido.entidad->turno( jugador );
        if( jugador->getHP() <= 0 ){
            return 0;
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