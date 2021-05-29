#ifdef MAZMORRA_H
#define MAZMORRA_H

#include <unordered_map>
#include "../model/entidad.h"
#include "../model/Item.h"

using std::unordered_map;

enum Tipo{
    VACIO, ENTIDAD, ITEM
};

typedef struct{
    typedef union{
        Entidad* entidad;
        Item* item;
    } content;
    Tipo tipo;
    
} Position;

class Mazmorra
{
private:
    unordered_map<int, Position*> mazmorra;
public:
    Mazmorra();
    Mazmorra(int);
    Position* getContenido(int) const;
    void setContenido(int, Position*);
    void quitar(int);
    bool ocupado(int);
};

#endif