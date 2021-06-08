#include "jugador.h"

constexpr int MIN = 1;
constexpr int MAX = 10;
constexpr int NUMEXITO = 6;

const int Jugador::bolsillos = 10;

Jugador::Jugador(): numItems(0), escape(false), puntosATK(20)
{
    for(int i = 1; i <= bolsillos; ++i)
        inventario.emplace(i, nullptr);
}

Jugador::Jugador(string nombre, int vidaMax, int pos): numItems(0), escape(false), puntosATK(20),
    Entidad(nombre, vidaMax, pos) {
    for (int i = 1; i <= bolsillos; ++i)
        inventario.emplace(i, nullptr);
}

int Jugador::getNumItems() const
{
    return numItems;
}

bool Jugador::getEscape() const
{
    return escape;
}

void Jugador::setEscape(bool escapado)
{
    escape = escapado;
}

void Jugador::mostrarInventario(){
    float usosLeft;
    for (auto it = inventario.begin(); it != inventario.end(); ++it){
        if( it->second != nullptr ){
            usosLeft = it->second->getUsos() / (float) it->second->getDesgaste();
            cout << it->first << ". " << it->second->getNombre();
            cout << "\tUsos restantes: " << ceil(usosLeft) << endl;
        }
    }
}

int Jugador::getATK() const
{
    return puntosATK;
}

void Jugador::setATK(int puntosATK){
    this->puntosATK = puntosATK;
}

void Jugador::addInventario(Item* item){
    if( numItems < bolsillos ){
        for (auto it = inventario.begin(); it != inventario.end(); ++it) {
            if (it->second == nullptr) {
                inventario[it->first] = item;
                ++numItems;
                item->setPocket(it->first);
                break;
            }
        }
    } else cout << "Inventario lleno" << endl;
}

void Jugador::eliminarItem(int itemPos)
{
    inventario[itemPos] = nullptr;
    --numItems;
}

void Jugador::turno(Entidad* enemigo)
{
    int opc;
    do{
        cout << "1. Golpe directo\n";
        cout << "2. Usar item\n";
        cout << "3. Escapar\n\n> ";
        cin >> opc;
        switch(opc){
            case 1:
                enemigo->setHP( enemigo->getHP() - puntosATK );
                opc = 0;
                break;
            case 2:
                mostrarInventario();
                cout << "Ingrese el item a usar\n> ";
                cin >> opc;
                try{
                    /*Item* item = inventario.at(opc);
                    item->usar(this, enemigo);*/
                    inventario.at(opc)->usar(this, enemigo);
                    opc = 0;
                }catch(std::out_of_range& e){
                    cout << "Item inexistente\n";
                }
                break;
            case 3:
                if( this->escapar() == true ) escape = true;
                opc = 0;
                break;
            default:
                cout << "Opcion invalida\n\n";
        }
    } while(opc != 0);
}

//Este método no es relevante en esta clase
Item* Jugador::soltar()
{
    return nullptr;
}

bool Jugador::escapar()
{
    srand(time(NULL));
    int numAleatorio = MIN + rand() % (MAX + 1);
    if(numAleatorio >= NUMEXITO){
        std::cout << "Escapas con exito!\n";
        return true;
    }
    else{
        std::cout << "Tu enemigo no te deja ir!\n";
        return false;
    }
}

Item* Jugador::consultar(int bolsillo)
{
    return inventario.at(bolsillo);
}