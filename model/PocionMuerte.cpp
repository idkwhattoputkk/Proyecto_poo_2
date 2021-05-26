#include "model/PocionMuerte.h"
// Variables constantes y estaticas para determinar si sera un exito utilizar la pocion
const int PocionMuerte::MIN = 1;
const int PocionMuerte::MAX = 10;
const int PocionMuerte::NUMEXITO = 6;

PocionMuerte::PocionMuerte(){}


bool PocionMuerte::hacerEfecto() {
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

PocionMuerte::~PocionMuerte()
{
    
}