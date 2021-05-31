#include "view.h"

View::View(): jugadorX(0), jugadorY(0)
{
    Dificultad dif = setDificultad();
    switch(dif){
        case EASY:
            controlador = MainController(dimEasy, numMonstersEasy, jefesEasy, EASY);
            break;
        case HARD:
            controlador = MainController(dimHard, numMonstersHard, jefesHard, HARD);
            break;
    }
}

Dificultad View::setDificultad()
{
    int opc;
    Dificultad dif;
    do{
        std::cout << "Elegir dificultad:\n1. Facil\n2.Dificil\n> ";
        try{
            std::cin >> opc;
        }catch( std::ios_base::failure &e ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida\n";
            opc = 0;
        }
        switch(opc){
            case 1:
                dif = EASY;
                return dif;
            case 2:
                dif = HARD;
                return dif;
            default:
                std::cout << "Opcion invalida\n\n";
                opc = 0;
        }
    } while(opc == 0);
}

void View::actualizarJugadorPos()
{   
    int dimension = getDimension();
    int mov;
    do{
        std::cout << "Mover jugador hacia:\n1. Arriba\n2. Abajo\n3. Izquierda\n";
        std::cout << "4. Derecha\n> ";
        try{
            std::cin >> mov;
        }catch( std::ios_base::failure &e ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida\n";
            opc = 0;
        }
        switch(mov){
            case 1:
                if( jugadorY - 1 >= UpperBorder ) --jugadorY; 
                break;
            case 2:
                if( jugadorY + 1 < dimension ) ++jugadorY;
                break;
            case 3:
                if( jugadorX - 1 >= LeftBorder ) --jugadorX;
                break;
            case 4:
                if( jugadorX + 1 < dimension ) ++jugadorX;
                break;
            default:
                std::cout << "Movimiento invalido\n\n";
                mov = 0;
        }
    } while(mov == 0);
    int pos = convertirPosLineal();
    controlador.actualizarJugadorPos(pos);
}

int View::convertirPosLineal()
{
    int dimension = getDimension();
    return jugadorX + jugadorY * dimension;
}

int View::getDimension() const
{
    switch( controlador.getDificultad() ){
        case EASY: 
            return dimEasy;
        case HARD:
            return dimHard;
    }
}

bool View::getEstadoJuego() const
{
    return controlador.getJugando();
}