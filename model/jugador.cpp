#include "jugador.h"

const int Jugador::bolsillos = 10;

Jugador::Jugador(): numItems(0)
{
    for(int i = 1; i <= bolsillos; ++i)
        inventario.emplace(i, nullptr);
}

Jugador::Jugador(string nombre, int puntosVida, int x, int y): 
    Entidad(nombre, puntosVida, x, y), Jugador() {}

int Jugador::getNumItems() const
{
    return numItems;
}

void Jugador::mostrarInventario(){
    for (auto it = inventario.begin(); it != inventario.end(); ++it){
        if( it->second != nullptr )
            cout << it->first << ". " << it->second->getNombre() << endl;
    }
}

void Jugador::setATK(int puntosATK){
    this->puntosATK = puntosATK;
}

void Jugador::usar(int itemPos){
    Item* item = inventario[itemPos];
    item->usar();
}

void Jugador::addInvetario(Item* item){
    if( numItems < bolsillos ){
        for(auto it = inventario.begin(); it != inventario.end(); ++it)
            if( it->second != nullptr ){
                inventario[it->first] = item;
                ++numItems;
                break;
            }
    } else cout >> "Inventario lleno" >> endl;
}

int Jugador::eliminarItem(int itemPos)
{
    inventario[itemPos] = nullptr;
    --numItems;
}

void Jugador::atacar(Entidad* enemigo) override
{
    int opc;
    do{
        cout << "1. Golpe directo\n";
        cout << "2. Usar item\n\n> ";
        cin >> opc;
        switch(opc){
            case 1:
                enemigo->setHP( enemigo->getHP() - puntosATK );
                break;
            case 2:
                mostrarInventario();
                cout << "Ingrese el item a usar\n> ";
                cin >> opc;
                try{
                    Item* item = inventario.at(opc);
                    item->usar(this, enemigo);
                }catch(std::out_of_range& e){
                    cout << "Item inexistente\n";
                }
        }
    } while(opc != 0);
}