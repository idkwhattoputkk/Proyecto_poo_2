#ifndef ARMA_H
#define ARMA_H

#include "Item.h"
#include "jugador.h"

//Clase arma
class Arma : public Item{
private: //atributos
    const int POTENCIA;
public: //metodos
    Arma();
    //Nombre,durabilidad,desgaste,frecuenciaAparicion,frecuenciaDesaparicion, Potencia
    Arma(string, int, int, int, int, int);
    int getPotencia();
    void usar(Entidad*, Entidad*) override;
    ~Arma() override;
};

#endif //ARMA_H