#include "Item.h"

//meotodos clase Item
Item::Item() : usos(DURABILIDAD), pocket(0), existencia(0) {}

Item::Item(string nombre, int durabilidad, int desgaste,
    int frecuenciaAparicion, int frecuenciaDesaparicion) : 
    nombre(nombre), DURABILIDAD(durabilidad), desgaste(desgaste), pos(-1), 
    frecuenciaAparicion(frecuenciaAparicion), frecuenciaDesaparicion(frecuenciaDesaparicion)
    Item() {}

Item::Item(const Item& item) : pocket(0), pos(-1), existencia(0)
{
    this->nombre = item.getNombre();
    this->DURABILIDAD = item.getDurabilidad();
    this->frecuenciaAparicion = item.getAparicion();
    this->frecuenciaDesaparicion = item.getDesaparicion();
    this->desgaste = item.getDesgaste();
    usos = DURABILIDAD;
}

int Item::getPos() const {
    return pos;
}

string Item::getNombre() const {
    return this->nombre;
}
void Item::mensaje() 
{
    cout << "Tomar " << nombre << " ?\n";
}

void Item::setPos(int pos) {
    this->pos = pos;
}

int Item::getUsos() const
{
    return usos;
}

void Item::setUsos(int usos)
{
    this->usos = usos;
}

int Item::getDesgaste() const
{
    return desgaste;
}

void Item::setDesgaste(int desgaste)
{
    this->desgaste = desgaste;
}

int Item::getDurabilidad() const
{
    return DURABILIDAD;
}

int Item::getExistencia() const
{
    return existencia;
}

void Item::setExistencia(int existencia)
{
    this->existencia = existencia;
}

int Item::getAparicion() const
{
    return frecuenciaAparicion;
}

int Item::getDesaparicion() const
{
    return frecuenciaDesaparicion;
}

Item::~Item() {}
