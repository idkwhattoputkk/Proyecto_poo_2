#include "takecontroller.h"

TomarController::TomarController() {}

bool TomarController::mensaje(Mazmorra* mazmorra, int pos){
    int opc;
    Position* contenido = mazmorra->getContenido(pos);
    Item* item = contenido->content;
    item->mensaje();
    do{
        std::cout << "1. Sí\n";
        std::cout << "2. No\n\n> ";
        try{
            std::cin >> opc;
        }catch( std::ios_base::failure &e ){
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Opcion invalida\n";
            opc = 0;
        }
        switch(opc){
            case 1:
                return true;
            case 2:
            default:
                return false;
        }
    }while(opc < 1 || opc > 2);
}

bool TomarController::addInventario(Mazmorra* mazmorra, Jugador* jugador, int pos){
    Position* contenido = mazmorra->getContenido(pos);
    Item* item = contenido->content;
    if( item->getName() == "Llave del Valhala" ) return true;
    jugador->addInventario(item);
    return false;
}