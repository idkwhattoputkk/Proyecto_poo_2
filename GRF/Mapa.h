#ifndef MAPA_H
#define MAPA_H

#include "olcPixelGameEngine.h"
#include <iostream>
#include <fstream>
#include <string>
#pragma once

class Mapa
{
private:
	int* m_indices;
	bool* m_solido;
	bool* m_enemy;
	bool* m_loot;
	int cantidad_enemy;
	int cantidad_loot;
	
public:
	int mapa_ancho;
	int mapa_alto;
	olc::Sprite* ptrSprite;
public:
	Mapa();
	int getIndice(int x, int y); //retorna el indice de la plantilla
	bool getSolido(int x, int y);//retirna si el bloque es solido o no
	bool getEnemy(int x, int y); //retorno si tiene enemigo
	bool getLoot(int x, int y); //retorna si tiene loot
	void asignacionEnemy(); //asigna donde se encontraran los enemigos aleatoriamente
	void asignacionLoot(); //asigna donde se encontrar el loot aleatoriamente
	bool Crear(std::string path, olc::Sprite*, int cantidad_enemy, int cantidad_loot);
	~Mapa();
};

class Mapa_facil : public Mapa
{
public:
	Mapa_facil();
};

class Mapa_normal : public Mapa
{
public:
	Mapa_normal();
};

class Mapa_dificil : public Mapa
{
public:
	Mapa_dificil();
};

#endif
