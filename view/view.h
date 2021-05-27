#ifdef VIEW_H
#define VIEW_H

#include "../controller/maincontroller.h"

class View
{
private:
    MainController controlador;
    int jugadorX, jugadorY;
public:
    View();
    void actualizarJugadorPos(int);
    int convertirPosLineal();
};

#endif