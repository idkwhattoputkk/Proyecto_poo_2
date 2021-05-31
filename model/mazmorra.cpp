#include "mazmorra.h"

Mazmorra::Mazmorra()
{
    //Inicialización del mapa
    for(int i = 0; i < dimension * dimension; ++i){
        Position contenido = {.content = nullptr, .tipo = VACIO};
        mazmorra.emplace(i, contenido);
    }

    Item* espada = new Arma("Hoja Celestial", foo, foo);
    Item* lanza = new Arma("Lanza Infernal", foo, foo);
    Item* cuchillo = new Arma("Daga desertico", foo, foo);
    Item* pocionATK = new PocionAtaque("Pocion de Ataque",1,1,3,3,foo);
    Item* pocionEsc = new PocionEscape("Pocion Escape",1,1,3,3);
    Item* pocionDeath = new PocionMuerte("Pocion de Muerte",1,1,3,3,foo);
    Item* pocionRes = new PocionResistencia("Pocion Resistencia",1,1,3,3,foo);
    Item* pocionVida = new PocionVida("Pocion de Vida",1,1,3,3,foo);
    listaGenerables.push_back(espada);
    listaGenerables.push_back(lanza);
    listaGenerables.push_back(cuchillo);
    listaGenerables.push_back(pocionATK);
    listaGenerables.push_back(pocionEsc);
    listaGenerables.push_back(pocionDeath);
    listaGenerables.push_back(pocionRes);
    listaGenerables.push_back(pocionVida);
}

Mazmorra::Mazmorra(int dimension, int numMonsters, int numBoss)
{
    //Monstruos tipo A
    for(int i = 0; i < percentMonstersA * (numMonsters - numBoss); ++i){
        int pos = randomPos(dimension);
        Entidad* entidad = new Villano("Lich", foo, pos);
        Position contenido = {.content = entidad, .tipo = ENTIDAD};
        mazmorra[pos] = &contenido;
    }
    //Monstruos tipo B
    for(int i = 0; i < percentMonstersB * (numMonsters - numBoss); ++i){
        int pos = randomPos(dimension);
        Entidad* entidad = new Villano("Cyberdemon", foo, pos);
        Position contenido = {.content = entidad, .tipo = ENTIDAD};
        mazmorra[pos] = &contenido;
    }
    //Monstruos tipo C
    for(int i = 0; i < percentMonstersC * (numMonsters - numBoss); ++i){
        int pos = randomPos(dimension);
        Entidad* entidad = new Villano("Hellish Baron", foo, pos);
        Position contenido = {.content = entidad, .tipo = ENTIDAD};
        mazmorra[pos] = &contenido;
    }
    //Jefes
    Item* recompensa = new Item("Llave del Valhala",1,1,1,1);

    if( numBoss > jefesEasy ){
        int pos = randomPos(dimension);
        Entidad* jefe = new Jefe("Titan", foo, foo, pos);
        Position contenido = {.content = jefe, .tipo = ENTIDAD};
        mazmorra[pos] = &contenido;

        pos = randomPos(dimension);
        Entidad* jefe = new Jefe("Dark Lord", foo, foo, pos);
        Position contenido = {.content = jefe, .tipo = ENTIDAD};
        mazmorra[pos] = &contenido;
    }
    int pos = randomPos(dimension);
    Entidad* jefe = new Jefe("Chaos", foo, foo, pos, recompensa);
    Position contenido = {.content = jefe, .tipo = ENTIDAD};
    mazmorra[pos] = &contenido;
}

Position* Mazmorra::getContenido(int pos) const
{
    return mazmorra[pos];
}

void Mazmorra::setContenido(int pos, Position* contenido)
{
    mazmorra[pos] = contenido;
}

void Mazmorra::quitar(int pos)
{
    Position vacio = {.content=nullptr, .tipo=VACIO};
    mazmorra[pos] = vacio;
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
            Item* item_2 = new Item( *it );
            item_2->setPos(pos);
            Position contenido = {.content=item_2, .tipo=ITEM};
            mazmorra[pos] = &contenido;
            listaExistentes.push_back( item_2 );
        }
    }
}