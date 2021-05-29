#include "maincontroller.h"

MainController::MainController() {}

void MainController::actualizarJugadorPos(int pos)
{
    posicionador.mover(&mazmorra, &jugador, pos);
}

bool MainController::terminarJuego()
{
    if( jugador.getHP() == 0.0 ) return false;
}

void MainController::mostrarGameStatus(string msg)
{
    /*Pendiente: se debe mirar como sacar este texto con la parte gráfica*/
    cout << msg << endl;
}