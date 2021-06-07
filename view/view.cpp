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

void View::jugar(){
    do{
        controlador.graficarMazmorra();
        actualizarJugadorPos();
    }while (getEstadoJuego() == true);
}

Dificultad View::setDificultad()
{
    int opc;
    Dificultad dif;
    do{
        std::cout << "Elegir dificultad:\n1. Facil\n2. Dificil\n> ";
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
    int x_pot = jugadorX, y_pot = jugadorY; //Valores potenciales de x e y
    do{
        std::cout << "Mover jugador hacia:\n1. Arriba\n2. Abajo\n3. Izquierda\n";
        std::cout << "4. Derecha\n> ";
        try{
                std::cin >> mov;
        }catch( std::ios_base::failure &e ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida\n\n";
            mov = 0;
        }
        switch(mov){
            case 1:
                if( jugadorY - 1 >= UpperBorder ){
                    y_pot = jugadorY - 1; 
                }else{
                    std::cout << "No puedes avanzar por ahi\n\n";
                    mov = 0;
                }
                break;
            case 2:
                if( jugadorY + 1 < dimension ){
                    y_pot = jugadorY + 1; 
                }else{
                    std::cout << "No puedes avanzar por ahi\n\n";
                    mov = 0;
                }
                break;
            case 3:
                if( jugadorX - 1 >= LeftBorder ){
                    x_pot = jugadorX - 1;
                }else{
                    std::cout << "No puedes avanzar por ahi\n\n";
                    mov = 0;
                }
                break;
            case 4:
                if( jugadorX + 1 < dimension ){
                    x_pot = jugadorX + 1; 
                }else{
                    std::cout << "No puedes avanzar por ahi\n\n";
                    mov = 0;
                }
                break;
            default:
                std::cout << "Movimiento invalido\n\n";
                mov = 0;
        }
    } while(mov == 0);
    int pos = convertirPosLineal(x_pot, y_pot);
    int result = controlador.actualizarJugadorPos(pos);
    if (result == 3) { //Es decir, que fue posible avanzar sin problemas
        jugadorX = x_pot;
        jugadorY = y_pot;
    }
}

int View::convertirPosLineal(int x_pot, int y_pot)
{
    int dimension = getDimension();
    return x_pot + y_pot * dimension;
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