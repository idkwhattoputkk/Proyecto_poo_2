#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>
#include <string>

using std::string;

class Ataque {
private:
    string nombre;
    const int potencia;
public:
    Ataque();
    Ataque(string, int);
    string getName();
    int getPotencia();
    ~Ataque();
};
#endif //ATAQUE_H
