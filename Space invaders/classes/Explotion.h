#pragma once
#include "GameObject.h"
#include "Game.h"

class Explotion : public GameObject
{

	float time;
	bool dead;

public:



	Explotion(float x, float y, float platos, float ypsos, float aktina, Game& game);



	void draw();

	bool isDead();

	void update();

	bool checkColision(GameObject* go);

};
