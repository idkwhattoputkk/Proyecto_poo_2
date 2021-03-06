#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>
#include "poscontroller.h"
#include "fightcontroller.h"
#include "takecontroller.h"
#include "../model/mazmorra.h"

using std::cout;
using std::endl;

enum Dificultad{
    EASY, HARD
};

class MainController
{
private:
    Mazmorra mazmorra;
    bool jugando;
    Jugador* jugador;
    Dificultad dificultad;
    PosController posicionador;
    TomarController gestor;
    PeleaController pelea;
public:
    MainController();
    MainController(int, int, int, Dificultad);
    int actualizarJugadorPos(int);
    void posicionar(int, Position*);
    bool terminarJuego();
    void mostrarGameStatus(string);
    int lanzarEvento(Tipo, int);
    bool getJugando() const;
    Dificultad getDificultad() const;
    void graficarMazmorra();
};

#endif