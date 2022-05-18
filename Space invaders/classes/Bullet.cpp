#pragma once

#include "Game.h"
#include "Bullet.h"
#include "Explotion.h"


Bullet::Bullet(int x, int y, int platos, int ypos, int aktina, Game& game)
	: GameObject(x, y, platos, ypos, aktina, game)
{
	br.texture = "assets\\bullet.png";
	br.outline_opacity = 0.0f;
	//speed = s;

}

void Bullet::draw()
{

	graphics::drawRect(x, y, platos, ypsos, br);
	graphics::resetPose();
}

void Bullet::update()
{
	y = y - 3;
}

// Eimai sfaira, ara mporw na sygkroustw me xeno
bool Bullet::checkColision(GameObject* go)
{
	Allien* d = dynamic_cast<Allien*> (go);
	Enemy* enemy = dynamic_cast<Enemy*> (go);

	// Gia na dw an einai Xenos kanw cast.
	// An petyxei to d den tha einai nullptr
	if (d != nullptr)
	{
		float apostasi_kentrwn = sqrt(pow(x - (d->getX()), 2) + pow(y - (d->getY()), 2));

		// Estw oti exw sygkrousi
		if (apostasi_kentrwn - aktina - d->getR() < 0)
		{
			anafora_game.score_up();
			//anafora_game.deleteGameObject(go);
			graphics::playSound("assets\\explotion.wav", 0.01f, false);
			Explotion* ex = new Explotion(d->getX(), d->getY(), 30, 30, 15, anafora_game);
			anafora_game.addGameObject(ex);

			return true;
		}
		
	}
	else if (enemy != nullptr)
	{
		float apostasi_kentrwn = sqrt(pow(x - (enemy->getX()), 2) + pow(y - (enemy->getY()), 2));

		// Estw oti exw sygkrousi
		if (apostasi_kentrwn - aktina - enemy->getR() < 0)
		{
			anafora_game.score_up();
			//anafora_game.deleteGameObject(go);
			graphics::playSound("assets\\explotion.wav", 0.01f, false);
			Explotion* ex = new Explotion(enemy->getX(), enemy->getY(), 30, 30, 15, anafora_game);
			anafora_game.addGameObject(ex);

			return true;
		}
	}
		
	return false;
}



bool Bullet::is_into_canvas()
{
	if (x < 0 || x > PLATOS_KAMVA || y < 0 || y > YPSOS_KAMVA)
		return false;
	else
		return true;
}