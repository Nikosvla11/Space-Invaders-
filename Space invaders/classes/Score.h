#pragma once

#include "GameObject.h"

class Score : public GameObject
{
	int score;

public:

	Score(int x, int y, int platos, int ypos, class Game& game)
		: GameObject(x, y, platos, ypos, 0, game)	// Den mas endiaferi h aktina, den tha sygkroustei
	{
		score = 0;
		br.texture = "assets\\coin.png";
		br.fill_color[0] = br.fill_color[1] = br.fill_color[2] = 1.0;
		br.fill_opacity = 1.0;
		br.outline_opacity = 0.0;
	}

	void auxiseScore()
	{
		score++;
	}

	void draw()
	{
		string text_score = to_string(score);

		graphics::drawRect(x, y, platos, ypsos, br);
		graphics::drawText(x + platos-20, y+10, 40, text_score, br);
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
