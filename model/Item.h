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
    static const int DURABILIDAD;
    int desgaste;
    int frecuenciaAparicion;
    int frecuenciaDesaparicion;
    int x;
    int y;
public:
    virtual ~Item();
    Item();
    Item(string nombre, int desgaste, int x,int y);
    virtual void usar() = 0;
    void mensaje();
    string getNombre() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);



};


#endif //ITEM_H
