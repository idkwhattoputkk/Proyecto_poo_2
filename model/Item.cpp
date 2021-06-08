#include "Item.h"

//meotodos clase Item
Item::Item() : DURABILIDAD(0), usos(DURABILIDAD), pocket(0), existencia(0), frecuenciaAparicion(0), 
    frecuenciaDesaparicion(0) {}

Item::Item(string nombre, int durabilidad, int desgaste,
    int frecuenciaAparicion, int frecuenciaDesaparicion) : 
    nombre(nombre), DURABILIDAD(durabilidad), desgaste(desgaste), pos(-1), 
    frecuenciaAparicion(frecuenciaAparicion), frecuenciaDesaparicion(frecuenciaDesaparicion) {}

Item::Item(const Item& item) : DURABILIDAD(item.getDurabilidad()), 
    frecuenciaAparicion(item.getAparicion()), frecuenciaDesaparicion(item.getDesaparicion()),
    pocket(0), pos(-1), existencia(0)
{
    this->nombre = item.getNombre();
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
    std::cout << "Tomar " << this->nombre << " ?\n";
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

void Item::setPocket(int pocket){
    this->pocket = pocket;
}

void Item::usar(Entidad* jugador, Entidad* enemigo){
}