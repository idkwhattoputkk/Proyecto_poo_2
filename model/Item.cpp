//
// Created by Emanuel Umaña on 25/05/21.
//

#include "Item.h"




Item::Item(){
   
}


Item::Item(string nombre, int desgaste, int x, int y) {
    this->nombre = nombre;
    this->desgaste = desgaste;
    this->x = x;
    this->y = y;

}
int Item::getX() const {
    return this->x;
}
int Item::getY() const {
    return this->y;
}

string Item::getNombre() const {
    return this->nombre;
}
void Item::mensaje() {}
void Item::setX(int x) {
    this->x = x;
}
void Item::setY(int y) {
    this->y = y;
}
Item::~Item()
{}
