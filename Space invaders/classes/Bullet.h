#pragma once

#include "GameObject.h"
#include "Game.h"



class Bullet : public GameObject
{

	
	

public:

	Bullet(int x, int y, int platos, int ypos, int aktina,  Game& game);

	void draw();

	void update();

	// Eimai Bullet, ara mporw na sygkroustw me xeno
	bool checkColision(GameObject* go);

	bool is_into_canvas();
};
