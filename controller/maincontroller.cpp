#include "maincontroller.h"

MainController::MainController() : jugando(true)
{
    //Siguiente: nombre, vidamax, pos
    jugador = new Jugador("Herz", 100, 0);
    posicionador = PosController();
    gestor = TomarController();
    pelea = PeleaController();
}

MainController::MainController(int dimension, int numMonsters, int numBoss,
    Dificultad dificultad) : dificultad(dificultad), jugando(false)
{
    mazmorra = Mazmorra(dimension, numMonsters, numBoss);
}

void MainController::actualizarJugadorPos(int pos)
{
    Tipo tipo = posicionador.mover(&mazmorra, jugador, pos);
    cout << "Tipo = " << tipo << std::endl;
    if( tipo != VACIO ){
        lanzarEvento( tipo, pos );
    }
}

void MainController::posicionar(int pos, Position* contenido)
{
    posicionador.posicionar(&mazmorra, pos, contenido);
}

bool MainController::terminarJuego()
{
    cout << "GAME OVER!\n";
    return true;
}

void MainController::mostrarGameStatus(string msg)
{
    /*Pendiente: se debe mirar como sacar este texto con la parte gráfica*/
    cout << msg << endl;
}

void MainController::lanzarEvento(Tipo contenido, int pos)
{
    switch( contenido ){
        case ENTIDAD:
            if( pelea.batalla(jugador, &mazmorra, pos) == false )
                terminarJuego();
            break;
        case ITEM:
            if( gestor.mensaje(&mazmorra, pos) == true ) 
                if( gestor.addInventario(&mazmorra, jugador, pos) == true ){
                    terminarJuego();
                }
            break;
        default:
            cout << "NO HAY NADA\n";
    }
}

Dificultad MainController::getDificultad() const
{
    return dificultad;
}

bool MainController::getJugando() const
{
    return jugando;
}