#include "PocionMuerte.h"
// Variables constantes y estaticas para determinar si sera un exito utilizar la pocion
const int PocionMuerte::MIN = 1;
const int PocionMuerte::MAX = 10;
const int PocionMuerte::NUMEXITO = 7;

PocionMuerte::PocionMuerte(){}

PocionMuerte::PocionMuerte(string nombre, int durabilidad, int desgaste, int frecAparicion, 
    int frecDesaparicion) : Item(nombre, durabilidad, desgaste, frecAparicion, 
    frecDesaparicion) {}

bool PocionMuerte::hacerEfecto()
{
    srand(time(NULL));
    numAleatorio = MIN + rand() % (MAX + 1);
    if(numAleatorio > NUMEXITO){
        std::cout << "Efecto exitoso\n";
        return true;
    } else{
        std::cout << "Los hados no estan a tu favor!\n";
        return false;
    }
}

void PocionMuerte::usar(Entidad* jugador, Entidad* enemigo)
{
    Jugador* player;
    do{
        player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
    }while( true );
    if( hacerEfecto() ) enemigo->setHP(0);
    player->eliminarItem(pocket);
    delete this;
}

PocionMuerte::~PocionMuerte() {}