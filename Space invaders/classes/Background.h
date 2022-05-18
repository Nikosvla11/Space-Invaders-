#pragma once

#include "GameObject.h"
#include"Game.h"

class Background : public GameObject
{
public:

	Background(int x, int y, int platos, int ypos, class Game& game)
		: GameObject(x, y, platos, ypos, 0, game)
	{
		br.fill_opacity = 1.0;
		br.texture = "assets\\background.png";
		br.outline_opacity = 0.0f;
	}

	void draw()
	{
		graphics::drawRect(x, y, platos, ypsos, br);
	}
	void update()
	{

	}
	bool checkColision(GameObject* go)
	{
		return false;
	}
};