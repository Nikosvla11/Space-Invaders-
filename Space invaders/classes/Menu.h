#pragma once

#include "Game.h"
#include "GameObject.h"


class Menu : public GameObject
{
	string menu = "Menu";
	string epilogi_a = "Easy";
	string epilogi_b = "Hard";

	int selector;
	bool on;

public:

	Menu(float x, float y, float platos, float ypsos, class Game& game);

	void draw();

	void update();

	bool checkColision(GameObject* go);

	int get_selector();

	bool isOn();

	void setOn();
};
