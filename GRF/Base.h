#ifndef BASE_H
#define BASE_H


#include "olcPixelGameEngine.h"
#include "Mapa.h"


class Base : public olc::PixelGameEngine
{
private:

	

	int alto_bloque;
	int ancho_bloque;

	int ancho_sprite_set;

	Mapa* mapa_actual;

	// Propiedades del jugador
	float fPlayerPosX;
	float fPlayerPosY;

	float fPlayerVelX;
	float fPlayerVelY;
	bool bPlayerOnGround;

	// Camera properties
	float fCameraPosX;
	float fCameraPosY;

	// Sprites
	olc::Sprite* spriteTiles;
	olc::Sprite* spriteMan;
	olc::Decal* decal_Man_Ptr;

	olc::Sprite* spriteEnemy;
	olc::Decal* decal_Enemy_Ptr;

	// Bandera de seleccion Sprite
	int nDirMovX;
	int nDirMovY;
	int enemy_select;

	// recursos necesarios para dibujar sprite jugador
	olc::vf2d position_player; //posicion del render
	float tile_Y_pos; //elegir que sprite para caminar
	olc::vf2d sourcePos;

	// recursos necesarios para dibujar sprite enemigo
	olc::vf2d position_enemy; //posicion del render
	float tile_pos_enemy; //elegir que mounstruo
	olc::vf2d sourcePos_enemy;


	//otras banderas
	int dificultad;
	bool batalla_flag;
	bool derrotar_jefe;

public:
	Base();
	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);
	void randomEnemy();
};

#endif


