#include "mazmorra.h"

Mazmorra::Mazmorra()
{
    //Nombre,durabilidad,desgaste,frecuenciaAparicion,frecuenciaDesaparicion, Potencia
    Item* espada = new Arma("Hoja Celestial", 2, 1, 2, 3, 50);
    Item* lanza = new Arma("Lanza Infernal", 3, 1, 2, 3, 40);
    Item* cuchillo = new Arma("Daga desertico", 4, 1, 2, 3, 30);
    Item* pocionATK = new PocionAtaque("Pocion de Ataque",1,1,3,3);
    Item* pocionEsc = new PocionEscape("Pocion Escape",1,1,3,3);
    Item* pocionDeath = new PocionMuerte("Pocion de Muerte",1,1,3,3);
    Item* pocionRes = new PocionResistencia("Pocion Resistencia",1,1,3,3,2);
    Item* pocionVida = new PocionVida("Pocion de Vida",1,1,3,3);
    listaGenerables.push_front(espada);
    listaGenerables.push_front(lanza);
    listaGenerables.push_front(cuchillo);
    listaGenerables.push_front(pocionATK);
    listaGenerables.push_front(pocionEsc);
    listaGenerables.push_front(pocionDeath);
    listaGenerables.push_front(pocionRes);
    listaGenerables.push_front(pocionVida);
}

Mazmorra::Mazmorra(int dimension, int numMonsters, int numBoss)
{
    //Inicialización del mapa
    for(int i = 0; i < dimension * dimension; ++i){
        Position* p = new Position;
        p->tipo = VACIO;
        p->contenido.entidad = nullptr;
        mazmorra.emplace( i, p );
    }

    //Monstruos tipo A
    vector<Entidad*> monsters(percentMonstersA * (numMonsters - numBoss), nullptr);
    vector<Position> positions(percentMonstersA * (numMonsters - numBoss));
    for(auto i = 0; i < positions.size(); ++i){
        int pos = randomPos(dimension);
        monsters[i] = new Villano("Lich", 60, pos);
        positions[i].tipo = ENTIDAD;
        positions[i].contenido.entidad = monsters[i];
        mazmorra[pos] = &positions[i];
    }
    //Monstruos tipo B
    monsters.resize(percentMonstersB * (numMonsters - numBoss));
    vector<Position> positionsB(percentMonstersB * (numMonsters - numBoss));
    positions.clear();
    for(auto i = 0; i < positionsB.size(); ++i){
        int pos = randomPos(dimension);
        monsters[i] = new Villano("Cyberdemon", 70, pos);
        positionsB[i].tipo = ENTIDAD;
        positionsB[i].contenido.entidad = monsters[i];
        mazmorra[pos] = &positionsB[i];
    }
    //Monstruos tipo C
    monsters.resize(percentMonstersC * (numMonsters - numBoss));
    vector<Position> positionsC(percentMonstersC * (numMonsters - numBoss));
    positionsB.clear();
    for(auto i = 0; i < positionsC.size(); ++i){
        int pos = randomPos(dimension);
        monsters[i] = new Villano("Hellish Baron", 80, pos);
        positionsC[i].tipo = ENTIDAD;
        positionsC[i].contenido.entidad = monsters[i];
        mazmorra[pos] = &positionsC[i];
    }
    //Jefes
    Item* recompensa = new Item("Llave del Valhala",1,1,1,1);

    if( numBoss > jefesEasy ){
        int pos = randomPos(dimension);
        Entidad* jefeA = new Jefe("Titan", 120, pos);
        Position pA = {.tipo = ENTIDAD};
        pA.contenido.entidad = jefeA;
        mazmorra[pos] = &pA;

        pos = randomPos(dimension);
        Entidad* jefeB = new Jefe("Dark Lord", 130, pos);
        Position pB = {.tipo = ENTIDAD};
        pB.contenido.entidad = jefeB;
        mazmorra[pos] = &pB;
    }
    int pos = randomPos(dimension);
    Entidad* jefe = new Jefe("Chaos", 140, pos, recompensa);
    Position p = {.tipo = ENTIDAD};
    p.contenido.entidad = jefe;
    mazmorra[pos] = &p;
}

Position* Mazmorra::getContenido(int pos)
{
    return mazmorra[pos];
}

void Mazmorra::setContenido(int pos, Position* contenido)
{
    mazmorra[pos] = contenido;
}

void Mazmorra::quitarContenido(int pos)
{
    Position vacio = {.tipo=VACIO};
    vacio.contenido.entidad = nullptr;
    vacio.contenido.item = nullptr;
    mazmorra[pos] = &vacio;
}

int Mazmorra::randomPos(int dimension)
{
    srand(time(NULL));
    int pos;
    do{
        pos = rand() % (dimension * dimension);
    } while( mazmorra[pos]->tipo != VACIO );
    return pos;
}

Tipo Mazmorra::ocupado(int pos)
{
    return mazmorra[pos]->tipo;
}

void Mazmorra::actualizarObjetos(int turnos)
{
    for(auto it = listaExistentes.begin(); it != listaExistentes.end();){
        Item* item = *it;
        item->setExistencia( item->getExistencia() + 1 );
        if( item->getExistencia() >= item->getDesaparicion() ){
            quitarContenido( item->getPos() );
            it = listaExistentes.erase(it);
            continue;
        }
        ++it;
    }

    for(auto it = listaGenerables.begin();  it != listaGenerables.end(); ++it){
        Item* item = *it;
        if( turnos % item->getAparicion() == 0 ){
            int dimension = sqrt( (float)mazmorra.size() );
            int pos = randomPos( dimension );
            Item* item_2 = new Item( *item );
            item_2->setPos(pos);
            Position p = {.tipo=ITEM};
            p.contenido.item = item_2;
            mazmorra[pos] = &p;
            listaExistentes.push_back( item_2 );
        }
    }
}