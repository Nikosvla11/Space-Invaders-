#pragma once

#include "Game.h"
#include "GameObject.h"
#include "Enemy.h"
#include "configuration.h"
#include "include/scancodes.h"				// Gia na vlepei ta pliktra pou pataw

class Spaceship : public GameObject
{
	int life;
	int gwnia;
	bool space;

public:

	Spaceship(int x, int y, int platos, int ypos, int aktina,int g, class Game& game)
		;

	void update();

	void draw();

	// Sygkoursi me xenous
	bool checkColision(GameObject* go);
};