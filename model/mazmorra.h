#ifdef MAZMORRA_H
#define MAZMORRA_H

#include <unordered_map>
#include "../model/entidad.h"
#include "../model/Item.h"

/*Pendiente:
Definir el union / struct con*/

using std::unordered_map;

class Mazmorra
{
private:
    unordered_map<int, Union*> mazmorra;
public:
    Mazmorra();
    Union* getContenido(int) const;
    void setContenido(int, Union*);
    void quitar(int);
};

#endif