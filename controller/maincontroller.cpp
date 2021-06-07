#include "maincontroller.h"

MainController::MainController() : jugando(true)
{
    //Siguiente: nombre, vidamax, pos
    //jugador = new Jugador("Herz", 100, 0);
    posicionador = PosController();
    gestor = TomarController();
    pelea = PeleaController();
}

MainController::MainController(int dimension, int numMonsters, int numBoss,
    Dificultad dificultad) : dificultad(dificultad), jugando(true)
{
    mazmorra = Mazmorra(dimension, numMonsters, numBoss);
}

int MainController::actualizarJugadorPos(int pos)
{
    Tipo tipo = posicionador.mover(&mazmorra, jugador, pos);
    if( tipo != VACIO ){
        return lanzarEvento( tipo, pos );
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

int MainController::lanzarEvento(Tipo contenido, int pos)
{
    int resultado = 0;
    switch( contenido ){
        case ENTIDAD:
            resultado = pelea.batalla(jugador, &mazmorra, pos);
            if ( resultado == 0 ) {
                terminarJuego();
                jugando = false;
                return resultado;
            }
            if (resultado == 1) {
                jugador->setEscape( false );
                return resultado;
            }
            break;
        case ITEM:
            if( gestor.mensaje(&mazmorra, pos) == true ) 
                if( gestor.addInventario(&mazmorra, jugador, pos) == true ){
                    cout << "HAS GANADO!\n\n";
                    terminarJuego();
                    jugando = false;
                    return 2;
                }
            break;
        default:
            cout << "NO APLICA\n";
            return 2;
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