#include "Game.h"
#include "Menu.h"


Menu::Menu(float x, float y, float platos, float ypsos, class Game& game)
	:GameObject(x, y, platos, ypsos, 0, game)
{
	on = true;
	selector = 1;

	br.fill_opacity = 1.0;
}

void Menu::draw()
{
	if (on == true)		// otan einai on
	{
		//br.texture = "assets\\menu.png";
		br.fill_color[0] = 0.7;
		br.fill_color[1] = 0.3;
		br.fill_color[2] = 0.5;
		graphics::drawRect(x, y, platos, ypsos, br);

		br.fill_color[0] = 0.0;
		br.fill_color[1] = 1.0;
		br.fill_color[2] = 0.3;

		graphics::drawText(x - 85, y-100 , 40, "Game Menu", br);
		//graphics::drawText(x - 85, y - 100, 40, "Our Game by : Venia Sykioti , Nikos vlachos", br);


		if (selector == 1)
			graphics::drawText(x - 30, y - 10, 30, epilogi_a + "*", br);
		else
			graphics::drawText(x - 30, y - 10 , 30, epilogi_a, br);

		if (selector == 2)
			graphics::drawText(x - 30, y + 60, 30, epilogi_b + "*", br);
		else
			graphics::drawText(x - 30, y + 60, 30, epilogi_b, br);
	}
}

void Menu::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_UP) == true)
	{
		selector = 1;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_DOWN) == true)
	{
		selector = 2;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN) == true)
	{
		on = false;
	}
}

bool Menu::checkColision(GameObject* go)
{
	return false;
}

int Menu::get_selector()
{
	return selector;
}

bool Menu::isOn()
{
	return on;
}

void Menu::setOn()
{
	on = true;
}