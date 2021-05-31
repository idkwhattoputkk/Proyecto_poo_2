#ifdef VIEW_H
#define VIEW_H

#include <iostream>
#include <ios>
#include "../controller/maincontroller.h"
#include "../model/mazmorra.h"

constexpr int UpperBorder = 0;
constexpr int LeftBorder = 0;

class View
{
private:
    MainController controlador;
    int jugadorX, jugadorY;
public:
    View();
    void jugar();
    Dificultad setDificultad();
    void actualizarJugadorPos();
    int getDimension() const;
    int convertirPosLineal();
    bool getEstadoJuego() const;
};

#endif