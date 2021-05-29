#ifdef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>
#include "poscontroller.h"
#include "fightcontroller.h"
#include "takecontroller.h"
#include "../model/mazmorra.h"

using std::cout;

class MainController
{
private:
    Mazmorra mazmorra;
    bool jugando;
    Entidad* jugador;
    PosController posicionador;
    TomarController gestor;
    PeleaController pelea;
public:
    MainController();
    void actualizarJugadorPos(int);
    void posicionar(int, Position*);
    bool terminarJuego();
    void mostrarGameStatus(string);
};

#endif