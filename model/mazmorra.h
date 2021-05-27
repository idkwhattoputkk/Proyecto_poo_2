#ifdef MAZMORRA_H
#define MAZMORRA_H

#include <unordered_map>
#include "../model/entidad.h"
#include "../model/Item.h"

using std::unordered_map;

typedef struct{
    typedef union{
        Entidad* entidad;
        Item* item;
    } content;

    enum Tipo = {ENTIDAD, ITEM};
} Position;

class Mazmorra
{
private:
    unordered_map<int, Position*> mazmorra;
public:
    Mazmorra();
    Position* getContenido(int) const;
    void setContenido(int, Position*);
    void quitar(int);
};

#endif