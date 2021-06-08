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

Mazmorra::Mazmorra(int dimension, int numMonsters, int numBoss): Mazmorra()
{
    //Inicialización del mapa
    for(int i = 0; i < dimension * dimension; ++i){
        Position* p = new Position;
        p->tipo = Tipo::VACIO;
        p->contenido.entidad = nullptr;
        mazmorra.emplace( i, p );
    }

    //Monstruos tipo A
    monstersA.resize(percentMonstersA * (numMonsters - numBoss), nullptr);
    positionsA.resize(percentMonstersA * (numMonsters - numBoss));
    for(auto i = 0; i < positionsA.size(); ++i){
        int pos = randomPos(dimension);
        monstersA[i] = new Villano("Lich", 60, pos);
        positionsA[i].tipo = ENTIDAD;
        positionsA[i].contenido.entidad = monstersA[i];
        mazmorra[pos] = &positionsA[i];
    }
    
    //Monstruos tipo B
    monstersB.resize(percentMonstersB * (numMonsters - numBoss));
    positionsB.resize(percentMonstersB * (numMonsters - numBoss));
    for(auto i = 0; i < positionsB.size(); ++i){
        int pos = randomPos(dimension);
        monstersB[i] = new Villano("Cyberdemon", 70, pos);
        positionsB[i].tipo = ENTIDAD;
        positionsB[i].contenido.entidad = monstersB[i];
        mazmorra[pos] = &positionsB[i];
    }

    //Monstruos tipo C
    monstersC.resize(percentMonstersC * (numMonsters - numBoss));
    positionsC.resize(percentMonstersC * (numMonsters - numBoss));
    for(auto i = 0; i < positionsC.size(); ++i){
        int pos = randomPos(dimension);
        monstersC[i] = new Villano("Hellish Baron", 80, pos);
        positionsC[i].tipo = ENTIDAD;
        positionsC[i].contenido.entidad = monstersC[i];
        mazmorra[pos] = &positionsC[i];
    }
    //Jefes
    Item* recompensa = new Item("Llave del Valhala",1,1,1,1);

    positionsBosses.resize(1);
    bosses.resize(1);
    if( numBoss > jefesEasy ){
        positionsBosses.resize(3);
        bosses.resize(3);
        int pos = randomPos(dimension);
        bosses[1] = new Jefe("Titan", 120, pos);
        positionsBosses[1] = {.tipo = ENTIDAD};
        positionsBosses[1].contenido.entidad = bosses[1];
        mazmorra[pos] = &positionsBosses[1];

        pos = randomPos(dimension);
        bosses[2] = new Jefe("Dark Lord", 130, pos);
        positionsBosses[2] = { .tipo = ENTIDAD };
        positionsBosses[2].contenido.entidad = bosses[2];
        mazmorra[pos] = &positionsBosses[2];
    }
    int pos = randomPos(dimension);
    bosses[0] = new Jefe("Chaos", 140, pos, recompensa);
    positionsBosses[0] = {.tipo = ENTIDAD};
    positionsBosses[0].contenido.entidad = bosses[0];
    mazmorra[pos] = &positionsBosses[0];
}

Position* Mazmorra::getContenido(int pos)
{
    return mazmorra[pos];
}

void Mazmorra::setContenido(int pos, Position* contenido)
{
    mazmorra[pos]->contenido.entidad = contenido->contenido.entidad;
    mazmorra[pos]->contenido.item = contenido->contenido.item;
    mazmorra[pos]->tipo = contenido->tipo;
}

void Mazmorra::quitarContenido(int pos)
{
    mazmorra[pos]->contenido.entidad = nullptr;
    mazmorra[pos]->contenido.item = nullptr;
    mazmorra[pos]->tipo = VACIO;
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
            /*Item* item_2 = new Item( *item );
            item_2->setPos(pos);
            Position p = {.tipo=ITEM};
            p.contenido.item = item_2;*/
            mazmorra[pos]->tipo = ITEM;
            mazmorra[pos]->contenido.item = new Item(*item);
            mazmorra[pos]->contenido.item->setPos( pos );
            listaExistentes.push_back(mazmorra[pos]->contenido.item);
        }
    }
}

void Mazmorra::graficarMazmorra() {
    int dimension = sqrt((float)mazmorra.size());
    for (int i = 0; i < mazmorra.size(); ++i) {
        if (i == 0) {
            cout << "I ";
            continue;
        }
        Tipo tipo = mazmorra[i]->tipo;
        switch (tipo) {
        case ITEM:
            cout << "O ";
            break;
        case ENTIDAD:
            if (mazmorra[i]->contenido.entidad->getName() == "Herz") {
                cout << "P ";
            }
            else {
                cout << "M ";
            }
            break;
        case VACIO:
            cout << "E ";
            break;
        default:
            cout << "? ";
        }
        if ( (i+1) % dimension == 0 ) {
            cout << endl;
        }
    }
}

void Mazmorra::entregarObjeto( int pos ) {
    for (auto it = listaExistentes.begin(); it != listaExistentes.end(); ++it) {
        int position = (*it)->getPos();
        if (position == pos) {
            listaExistentes.erase( it );
            break;
        }
    }
}