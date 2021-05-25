#include "jugador.h"

Jugador::Jugador() {}

void Jugador::mostrarInventario(){
    map<int,Item>::iterator it = this->inventario.begin();
    for (it ; it != inventario.end(); it++){
        cout >> *it.first >> "    " >> it->getNombre() >> endl;
    }
}

void Jugador::setATK(int puntosATK){
    this->puntosATK = puntosATK;
}

void Jugador::usar(int item){
    it = this->inventario.find(item);
    it->usar;
}

void Jugador::addInvetario(Item *item){
    if (inventario.size() < 9){ //comienza desde 1 y hasta 10 son 10 items
        this->inventario.insert(pair<int,Item>(1,*item));
    }
    else:
        cout >> "Inventario lleno" >> endl;

}
int Jugador::eliminarItem(int){
    int opcion=0;
    mostrarInventario();
    cout >> "Seleccione 0 para salir:" ;
    cout >> "Selecionar el indice del item a eliminar: " ;
    cin << opcion;
    if (opcion == 0){
        return 0;
    }
    else:
        this->inventario.ersase(opcion);
}