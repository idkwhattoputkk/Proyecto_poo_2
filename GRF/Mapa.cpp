#include "Mapa.h"

Mapa::Mapa() {
	m_indices = nullptr;
	m_solido = nullptr;
	m_enemy = nullptr;
	m_loot = nullptr;
	mapa_ancho = 0;
	mapa_alto = 0;
	ptrSprite = nullptr;
}


int Mapa::getIndice(int x, int y){
	if (x >= 0 && x < mapa_ancho && y >= 0 && y < mapa_alto) {
		return m_indices[y * mapa_ancho + x];
	}
	else {
		return 0;
	}
}

bool Mapa::getSolido(int x, int y) {
	if (x >= 0 && x < mapa_ancho && y >= 0 && y < mapa_alto) {
		return m_solido[y * mapa_ancho + x];
	}
	else {
		return 0;
	}
}

bool Mapa::getEnemy(int x, int y) {
	if (x >= 0 && x < mapa_ancho && y >= 0 && y < mapa_alto) {
		return m_enemy[y * mapa_ancho + x];
	}
	else {
		return 0;
	}
}

bool Mapa::getLoot(int x, int y) {
	if (x >= 0 && x < mapa_ancho && y >= 0 && y < mapa_alto) {
		return m_loot[y * mapa_ancho + x];
	}
	else {
		return 0;
	}
}

void Mapa::asignacionEnemy() {
	int posX, posY,count=0;
	srand(time(NULL));


	for (int i = 0; i <= mapa_ancho * mapa_alto; i++) {
		m_enemy[i] = 0;
	}


	while (count<cantidad_enemy) {
		
		posX = 1 + rand() % mapa_ancho;
		posY = 1 + rand() % mapa_alto;


		if (!(getSolido(posX,posY)) && posX >= 5 && posY >= 5) {
			m_enemy[posY * mapa_ancho + posX] = 1 ;
			count = count+1;
		}

	}

	
}

void Mapa::asignacionLoot() {
	int posX, posY, count = 0;
	srand(time(NULL));

	for (int i = 0; i <= mapa_ancho * mapa_alto; i++) {
		m_loot[i] = 0;
	}

	while (count < cantidad_loot) {
		
		posX = 1 + rand() % mapa_ancho;
		posY = 1 + rand() % mapa_alto;

		
		if ( !(getSolido(posX, posY)) && !(getEnemy(posX, posY)) ) {
			m_loot[posY * mapa_ancho + posX] = 1;
			count = count+1;
		}

	}

}

bool Mapa::Crear(std::string path, olc::Sprite* ptrSprite, int cantidad_enemy, int cantidad_loot) {
	this->ptrSprite = ptrSprite;
	this->cantidad_enemy = cantidad_enemy;
	this->cantidad_loot = cantidad_loot;
	std::ifstream data(path, std::ios::in | std::ios::binary);
	if (data.is_open()) {
		data >> mapa_ancho >> mapa_alto;
		this->m_solido = new bool[mapa_ancho * mapa_alto];
		this->m_indices = new int[mapa_ancho * mapa_alto];
		this->m_enemy = new bool[mapa_ancho * mapa_alto];
		this->m_loot = new bool[mapa_ancho * mapa_alto];

		for (int i = 0; i < mapa_ancho * mapa_alto; i++ ) {
			data >> m_indices[i];
			data >> m_solido[i];
		}


		asignacionEnemy();
		//asignacionLoot();

		return true;
	}

	return false;
}


Mapa::~Mapa() {
	delete[] m_solido;
	delete[] m_indices;
	delete[] m_enemy;
	delete[] m_loot;

}


Mapa_facil::Mapa_facil() {
	Crear("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\mapa_facil.lvl",
		new olc::Sprite("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\sprites\\mapa.png"),
		25,
		3
		);
}

Mapa_normal::Mapa_normal() {
	Crear("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\mapa_normal.lvl",
		new olc::Sprite("C:\\Users\\sebastian\\Desktop\\POO\\FirstGame\\FirstGame\\sprites\\mapa.png"),
		35,
		3
	);
}

