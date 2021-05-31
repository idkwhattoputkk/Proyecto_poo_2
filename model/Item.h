#ifndef ITEM_H
#define ITEM_H
//includes
#include <string>

using std::string;
//Class item
class Item {
protected:
    string nombre;
    const int DURABILIDAD;
    const int frecuenciaAparicion;
    const int frecuenciaDesaparicion;
    int usos, pocket, desgaste, pos, existencia;
public://Metodos
    Item();
    Item(string,int,int,int,int);
    Item(const Item&);
    virtual void usar(Entidad*, Entidad*) = 0;
    void mensaje();
    string getNombre() const;
    int getPos() const;
    void setPos(int);
    int getPocket() const;
    void setPocket(int);
    int getUsos() const;
    void setUsos(int);
    int getDesgaste() const;
    void setDesgaste(int);
    int getDurabilidad() const;
    int getExistencia() const;
    void setExistencia(int);
    int getAparicion() const;
    int getDesaparicion() const;
    virtual ~Item();
};
#endif //ITEM_H
