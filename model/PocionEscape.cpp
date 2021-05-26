#include "model/PocionEscape.h"
// Variables constantes y estaticas para determinar si sera un exito utilizar la pocion
const int PocionEscape::MIN = 1;
const int PocionEscape::MAX = 10;
const int PocionEscape::NUMEXITO = 6;
PocionEscape::PocionEscape()
{
    
}

PocionEscape::~PocionEscape()
{
    
}

bool PocionEscape::hacerEfecto() {
    srand(time(NULL));
    bool flag;
    numAleatorio = 1+rand()%10;
    if(numAleatorio == NUMEXITO){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}
