#include "PocionEscape.h"
// Variables constantes y estaticas para determinar si sera un exito utilizar la pocion
const int PocionEscape::MIN = 1;
const int PocionEscape::MAX = 10;
const int PocionEscape::NUMEXITO = 5;

PocionEscape::PocionEscape() {}

PocionEscape::PocionEscape(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion) : Item(nombre, durabilidad, desgaste, frecAparicion, 
    frecDesaparicion) {}

PocionEscape::~PocionEscape() {}

bool PocionEscape::hacerEfecto() {
    srand(time(NULL));
    numAleatorio = MIN + rand() % (MAX + 1);
    if(numAleatorio >= NUMEXITO){
        std::cout << "Escapas con exito!\n";
        return true;
    }
    else{
        std::cout << "Tu enemigo no te deja ir!\n";
        return false;
    }
}

void PocionEscape::usar(Entidad* jugador, Entidad* enemigo) override
{
    if( hacerEfecto() ) jugador->setEscape(true);
    jugador->eliminarItem(pocket);
    ~PocionMuerte();
}