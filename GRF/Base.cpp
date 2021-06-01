#include "Base.h"

Base::Base() {

	

	alto_bloque = 16;
	ancho_bloque = 16;

	ancho_sprite_set = 10;

	mapa_actual = nullptr;


	fPlayerPosX = 1.0f;
	fPlayerPosY = 1.0f;

	fPlayerVelX = 0.0f;
	fPlayerVelY = 0.0f;

	fCameraPosX = 0.0f;
	fCameraPosY = 0.0f;

	spriteTiles = nullptr;

	spriteMan = nullptr;
	decal_Man_Ptr = nullptr;

	spriteEnemy = nullptr;
	decal_Enemy_Ptr = nullptr;

	batalla_flag = 0;

	nDirMovX = 0;
	nDirMovY = 0;

	derrotar_jefe = 0;
}

bool Base::OnUserCreate()
{

	do
	{
	std::cout << "Escoger nivel de dificultad:" << std::endl;
	std::cout << "1. Facil" << std::endl;
	std::cout << "2. Normal" << std::endl;
	std::cout << "Opcion: ";
	std::cin >> dificultad;
	} while (dificultad < 1 || dificultad > 2);

	switch (dificultad) {
	case 1:
		mapa_actual = new Mapa_facil;
		break;

	case 2:
		mapa_actual = new Mapa_normal;
		break;

	
	}
	

	spriteMan = new olc::Sprite("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\prueba_Hertz.png");
	decal_Man_Ptr = new olc::Decal(spriteMan);

	spriteEnemy = new olc::Sprite("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\enemigos.png");
	decal_Enemy_Ptr = new olc::Decal(spriteEnemy);

	
	

	return true;
}

bool Base::OnUserUpdate(float fElapsedTime)
{


	fPlayerVelX = 0.0f;
	fPlayerVelY = 0.0f;


	// Entradas por teclado
	if (IsFocused() && batalla_flag == 0) {

		if (GetKey(olc::Key::W).bHeld)
		{
			fPlayerVelY = -4.0f;
		}

		if (GetKey(olc::Key::S).bHeld)
		{
			fPlayerVelY = 4.0f;
		}

		if (GetKey(olc::Key::A).bHeld)
		{
			fPlayerVelX -= 4.0f;
			nDirMovY = 1;
		}

		if (GetKey(olc::Key::D).bHeld)
		{
			fPlayerVelX += 4.0f;
			nDirMovY = 0;
		}

	}

	if (IsFocused()) {
		if (GetKey(olc::Key::G).bHeld)
		{
			derrotar_jefe = 1;
		}

		if (GetKey(olc::Key::H).bHeld)
		{
			batalla_flag = 0;
		}
	}

	// Limitar velocida
	if (fPlayerVelX > 10.0f)
		fPlayerVelX = 10.0f;

	if (fPlayerVelX < -10.0f)
		fPlayerVelX = -10.0f;

	if (fPlayerVelY > 100.0f)
		fPlayerVelY = 100.0f;

	if (fPlayerVelY < -100.0f)
		fPlayerVelY = -100.0f;

	// Calcular posibles pocisiones
	float fNewPlayerPosX = fPlayerPosX + fPlayerVelX * fElapsedTime;
	float fNewPlayerPosY = fPlayerPosY + fPlayerVelY * fElapsedTime;

	// Check de loot

	if (mapa_actual->getLoot(fNewPlayerPosX + 0.0f, fNewPlayerPosY + 0.0f) == 1){
		//rotina para tomar objeto
		std::cout << "Aqui esta el loot" << std::endl;
	}

	if (mapa_actual->getLoot(fNewPlayerPosX + 0.0f, fNewPlayerPosY + 1.0f) == 1){
		//rutina para tomar objeto
		std::cout << "Aqui esta el loot" << std::endl;
	}

	if (mapa_actual->getLoot(fNewPlayerPosX + 1.0f, fNewPlayerPosY + 0.0f) == 1){
		//rutina para tomar objeto
		std::cout << "Aqui esta el loot" << std::endl;
	}

	if (mapa_actual->getLoot(fNewPlayerPosX + 1.0f, fNewPlayerPosY + 1.0f) == 1){
		//rutina para tomar objeto
		std::cout << "Aqui esta el loot" << std::endl;
	}
	

	// Check de Enemigos
	
	if (mapa_actual->getEnemy(fNewPlayerPosX + 0.0f, fNewPlayerPosY + 0.0f) == 1) {
		//rutina para inicar battalla
		batalla_flag = 1;
		
	}

	if (mapa_actual->getEnemy(fNewPlayerPosX + 0.0f, fNewPlayerPosY + 1.0f) == 1) {
		//rutina para inicar battalla
		batalla_flag = 1;
		
	}

	if (mapa_actual->getEnemy(fNewPlayerPosX + 1.0f, fNewPlayerPosY + 0.0f) == 1) {
		//rutina para inicar battalla
		batalla_flag = 1;
		
	}

	if (mapa_actual->getEnemy(fNewPlayerPosX + 1.0f, fNewPlayerPosY + 1.0f) == 1) {
		//rutina para inicar battalla
		batalla_flag = 1;
		
	}

	

	// Check collisiones
	if (fPlayerVelX <= 0) // Moving Left
	{
		if (mapa_actual->getSolido(fNewPlayerPosX + 0.0f, fPlayerPosY + 0.0f) || mapa_actual->getSolido(fNewPlayerPosX + 0.0f, fPlayerPosY + 0.9f))
		{
			fNewPlayerPosX = (int)fNewPlayerPosX + 1;
			fPlayerVelX = 0;
		}
	}
	else // Moving Right
	{
		if (mapa_actual->getSolido(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.0f) || mapa_actual->getSolido(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.9f))
		{
			fNewPlayerPosX = (int)fNewPlayerPosX;
			fPlayerVelX = 0;

		}
	}

	bPlayerOnGround = false;
	if (fPlayerVelY <= 0) // Moving Up
	{
		if (mapa_actual->getSolido(fNewPlayerPosX + 0.0f, fNewPlayerPosY) || mapa_actual->getSolido(fNewPlayerPosX + 0.9f, fNewPlayerPosY))
		{
			fNewPlayerPosY = (int)fNewPlayerPosY + 1;
			fPlayerVelY = 0;
		}
	}
	else // Moving Down
	{
		if (mapa_actual->getSolido(fNewPlayerPosX + 0.0f, fNewPlayerPosY + 1.0f) || mapa_actual->getSolido(fNewPlayerPosX + 0.9f, fNewPlayerPosY + 1.0f))
		{
			fNewPlayerPosY = (int)fNewPlayerPosY;
			fPlayerVelY = 0;
			bPlayerOnGround = true; // Player has a solid surface underfoot
			nDirMovX = 0;
		}
	}

	// Actualizar posicion
	fPlayerPosX = fNewPlayerPosX;
	fPlayerPosY = fNewPlayerPosY;

	// Actualizar Camara
	fCameraPosX = fPlayerPosX;
	fCameraPosY = fPlayerPosY;

	// Dibujar Nivel
	int nTileWidth = ancho_bloque;
	int nTileHeight = alto_bloque;
	int nVisibleTilesX = ScreenWidth() / nTileWidth;
	int nVisibleTilesY = ScreenHeight() / nTileHeight;

	// Calcular offset de vision
	float fOffsetX = fCameraPosX - (float)nVisibleTilesX / 2.0f;
	float fOffsetY = fCameraPosY - (float)nVisibleTilesY / 2.0f;

	// Limites de camara
	if (fOffsetX < 0) fOffsetX = 0;
	if (fOffsetY < 0) fOffsetY = 0;
	if (fOffsetX > mapa_actual->mapa_ancho - nVisibleTilesX) fOffsetX = mapa_actual->mapa_ancho - nVisibleTilesX;
	if (fOffsetY > mapa_actual->mapa_alto - nVisibleTilesY) fOffsetY = mapa_actual->mapa_alto - nVisibleTilesY;

	// Offeset para movimiento
	float fTileOffsetX = (fOffsetX - (int)fOffsetX) * nTileWidth;
	float fTileOffsetY = (fOffsetY - (int)fOffsetY) * nTileHeight;

	// Dibujar bloques visibles
	for (int x = -1; x < nVisibleTilesX + 1; x++)
	{
		for (int y = -1; y < nVisibleTilesY + 1; y++)
		{
			int idx = mapa_actual->getIndice(x + fOffsetX, y + fOffsetY);
			int sx = idx % ancho_sprite_set;
			int sy = idx / ancho_sprite_set;

			DrawPartialSprite(x * nTileWidth - fTileOffsetX, y * nTileHeight - fTileOffsetY, mapa_actual->ptrSprite, sx * nTileWidth, sy * nTileHeight, nTileWidth, nTileHeight);

		}
	}

	// Dibujar entidades

	olc::vf2d size = { 16.0f, 16.0f }; //tamaño del render

	//cuando aparece un enemigo se detiene el jugador 
	if (batalla_flag == 0) {
		randomEnemy();
		tile_Y_pos = nDirMovY * nTileWidth;
		sourcePos = { 0.0f, tile_Y_pos };
		position_player = { (fPlayerPosX - fOffsetX) * nTileWidth, (fPlayerPosY - fOffsetY) * nTileWidth };
		position_enemy = { (fPlayerPosX - fOffsetX - 1) * nTileWidth,  (fPlayerPosY - fOffsetY ) * nTileWidth };
	}

	
	// dibuja puerta cuando jefe es derrotado
	if (derrotar_jefe == 1) {
		DrawPartialSprite(0, nTileWidth, mapa_actual->ptrSprite, 0 * nTileWidth, 2 * nTileWidth, nTileWidth, nTileHeight);
	}

	if (batalla_flag == 1) {	
		
		tile_pos_enemy = enemy_select * nTileWidth;
		sourcePos_enemy = { tile_pos_enemy, 0.0f };
		DrawPartialDecal(position_enemy, size, decal_Enemy_Ptr, sourcePos_enemy, size);
		
	}
	
	DrawPartialDecal(position_player, size, decal_Man_Ptr, sourcePos, size);
	

	return true;
}

void Base::randomEnemy() {
	int pos, cantidad_enemigos = 7;
	srand(time(NULL));

	pos = 0 + rand() % cantidad_enemigos;

	this->enemy_select = pos;
}