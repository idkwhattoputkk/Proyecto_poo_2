#include "PocionResistencia.h"
//Constructores y metodos de la clase pocion de resistencia
PocionResistencia::PocionResistencia(): puntosResistencia(0){}

PocionResistencia::PocionResistencia(string nombre, int durabilidad, int desgaste, 
    int frecAparicion, int frecDesaparicion, int puntosResistencia) :
    puntosResistencia(puntosResistencia), Item(nombre, durabilidad, desgaste, 
    frecAparicion, frecDesaparicion) {}

int PocionResistencia::getRP(){
    return puntosResistencia;
}

void PocionResistencia::usar(Entidad* jugador, Entidad* enemigo)
{
    Jugador* player;
    Item* item;
    do{
        player = dynamic_cast<Jugador*>(jugador);
        if( player == nullptr ) continue;
    }while( true );
    player->mostrarInventario();
    int opc;
    do{
        cout << "Ingrese el item a renovar\n";
        cout << "NOTA: si usas esta pocion sobre otra pocion, se pierde el efecto\n> ";
        cin >> opc;
        try{
            item = player->consultar(opc);
            item->usar(jugador, enemigo);
        } catch(std::out_of_range& e){
            cout << "Item inexistente\n\n";
            opc = 0;
        }
    } while( opc == 0 );

    if( item->getUsos() + puntosResistencia < item->getDurabilidad() )
        item->setUsos( item->getUsos() + puntosResistencia );
    else item->setUsos( item->getDurabilidad() );

    player->eliminarItem(pocket);
    delete this;
}

PocionResistencia::~PocionResistencia() {}

