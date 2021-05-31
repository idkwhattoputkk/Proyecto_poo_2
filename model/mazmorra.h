#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <forward_list>
#include <list>
#include <queue>
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

struct Position{
    union content{
        Entidad* entidad;
        Item* item;
    };
    
    Tipo tipo;
};

class Mazmorra
{
private:
    unordered_map<int, Position*> mazmorra;
    forward_list<Item*> listaGenerables;
    list<Item*> listaExistentes;
public:
    Mazmorra();
    Mazmorra(int, int, int);
    Position* getContenido(int) const;
    void setContenido(int, Position*);
    void quitar(int);
    int randomPos(int);
    Tipo ocupado(int);
    void actualizarObjetos(int);
};

#endif