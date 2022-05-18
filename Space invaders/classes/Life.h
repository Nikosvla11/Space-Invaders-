#pragma once

#include "GameObject.h"

class Life : public GameObject
{
	int lifes;

public:

	Life(int x, int y, int platos, int ypos, class Game& game)
		: GameObject(x, y, platos, ypos, 0, game)	// Den mas endiaferi h aktina, den tha sygkroustei
	{
		lifes = 3;
		br.texture = "assets\\life.png";
		br.fill_color[0] = br.fill_color[1] = br.fill_color[2] = 1.0;
		br.fill_opacity = 1.0;
		br.outline_opacity = 0.0;
	}

	void meiwseLife()
	{
		lifes--;
	}

	int getLifes()
	{
		return lifes;
	}

	void draw()
	{
		if (lifes == 1)
		{
			graphics::drawRect(x, y, platos, ypsos, br);
		}

		if (lifes == 2)
		{
			graphics::drawRect(x, y, platos, ypsos, br);
			graphics::drawRect(x + platos, y, platos, ypsos, br);
		}

		if (lifes == 3)
		{
			graphics::drawRect(x, y, platos, ypsos, br);
			graphics::drawRect(x + platos, y, platos, ypsos, br);
			graphics::drawRect(x + 2 * platos, y, platos, ypsos, br);
		}
	}

	void update()
	{

	}

	// Ypoxrewtiki yperkalypsi, epistrefw false
	bool checkColision(GameObject* go)
	{
		return false;
	}
};
