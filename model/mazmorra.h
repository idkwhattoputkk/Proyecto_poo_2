#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_map>
#include "entidad.h"
#include "Item.h"
#include "jefe.h"
#include "villano.h"
#include "Arma.h"
#include "PocionAtaque.h"
#include "PocionEscape.h"
#include "PocionMuerte.h"
#include "PocionResistencia.h"
#include "PocionVida.h"

using std::vector;

//Dimensiones y numero de monstruos por dificultad
constexpr int dimEasy = 10;
constexpr int dimHard = 15;
constexpr int numMonstersEasy = 25;
constexpr int numMonstersHard = 35;

constexpr int jefesEasy = 1;
constexpr int jefesHard = 3;

constexpr float percentMonstersA = 0.5;
constexpr float percentMonstersB = 0.3;
constexpr float percentMonstersC = 0.2;

constexpr float numItems = 0.2;

using std::unordered_map;
using std::forward_list;
using std::list;

enum Tipo{
    VACIO, ENTIDAD, ITEM
};

union content{
    Entidad* entidad;
    Item* item;
};

struct Position{
    content contenido;    
    Tipo tipo;
};

class Mazmorra
{
private:
    unordered_map<int, Position*> mazmorra;
    forward_list<Item*> listaGenerables;
    list<Item*> listaExistentes;
    vector<Entidad*> monstersA, monstersB, monstersC, bosses;
    vector<Position> positionsA, positionsB, positionsC, positionsBosses;
public:
    Mazmorra();
    Mazmorra(int, int, int);
    Position* getContenido(int);
    void setContenido(int, Position*);
    void quitarContenido(int);
    int randomPos(int);
    Tipo ocupado(int);
    void actualizarObjetos(int);
};

#endif