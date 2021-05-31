#include "maincontroller.h"

MainController::MainController() : jugando(true)
{
    //Siguiente: nombre, puntosvida, vidamax, pos
    jugador = new Jugador("Herz", foo, foo, foo);
    posicionador = PosController();
    gestor = TomarController();
    pelea = PeleaController();
}

MainController::MainController(int dimension, int numMonsters, int numBoss,
    Dificultad dificultad) : dificultad(dificultad), MainController()
{
    mazmorra = Mazmorra(dimension, numMonsters, numBoss);
}

void MainController::actualizarJugadorPos(int pos)
{
    posicionador.mover(&mazmorra, &jugador, pos);
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
                gestor.addInventario(&mazmorra, jugador, pos);
            break;
    }
}

Dificultad getDificultad() const
{
    return dificultad;
}