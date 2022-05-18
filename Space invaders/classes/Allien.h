#pragma once

#include "Game.h"
#include "Spaceship.h"
#include "GameObject.h"

class Spaceship;

class Allien : public GameObject
{
	int life;
	float fX, fY;

public:

	Allien(int x, int y, int platos, int ypos, int aktina, Game& game);

	void draw();

	void update();

	// Eimai enemy, ara mporw na sygkroustw me diastimoploio h sfaira
	bool checkColision(GameObject* go);
	//bool has_life();
	//void katastrofi();

	void bounce();

	bool is_into_canvas();
};
