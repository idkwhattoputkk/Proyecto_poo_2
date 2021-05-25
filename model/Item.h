//
// Created by Emanuel Umaña on 25/05/21.
//

#ifndef ITEM_H
#define ITEM_H
//includes
#include <string>

using std::string;
//Class item
class Item {
    // Attributes and constants
protected:
    string nombre;
    static const int durabilidad;
    int desgaste;
    int frecuenciaAparicion;
    int frecuenciaDesaparicion;
    int x;
    int y;
public:
    virual ~Item();
    Item();
    Item(string nombre, int, int,int);
    virual void usar() = 0;
    void mensaje();
    string getNombre() const;
    int getX() const;
    int getY() const;
    void setX(int );
    void setY(int)



};


#endif //ITEM_H
