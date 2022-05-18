#pragma once

#include "Game.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Allien.h"
#include "Explotion.h"
#include "Spaceship.h"
#include "configuration.h"
#include "include/scancodes.h"				// Gia na vlepei ta pliktra pou pataw


Spaceship::Spaceship(int x, int y, int platos, int ypos, int aktina, int g, class Game& game)
	: GameObject(x, y, platos, ypos, aktina, game)
{
	life = 3;
	br.texture = "assets\\spaceship.png";
	br.outline_opacity = 0.0;

}

void Spaceship::update()
{

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		x = x - 2;
		if (x - aktina <= 0)
			x = aktina - 20;
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		x = x + 2;
		if (x + aktina >= PLATOS_KAMVA)
			x = x - 1;
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		graphics::playSound("assets\\shoot1.wav", 0.05f, false);
		Bullet* s = new Bullet(x, y - 40, 20, 20, 10, anafora_game);

		anafora_game.addGameObject(s);
	}


}

void Spaceship::draw()
{

	// Zwgrafise to antikeimeno
	graphics::drawRect(x, y, platos, ypsos, br);

	// Afou to zwgrafisei, epanaferw tin gwnia sxediasis
	graphics::resetPose();
}

// Sygkoursi me enemies
bool Spaceship::checkColision(GameObject* go)
{
	Allien* allien = dynamic_cast<Allien*> (go);
	Enemy* enemy = dynamic_cast<Enemy*> (go);

	// Gia na dw an einai xenos kanw cast.
	// An petyxei to enemy den tha einai nullptr
	if (allien != nullptr)
	{
		float apostasi_kentrwn = sqrt(pow(x - (allien->getX()), 2) + pow(y - (allien->getY()), 2));

		// Estw oti exw sygkrousi
		if (apostasi_kentrwn - aktina - allien->getR() < 0)
		{
			anafora_game.life_down();

			graphics::playSound("assets\\explotion.wav", 0.1f, false);
			Explotion* ex = new Explotion(allien->getX(), allien->getY(), 50, 50, 15, anafora_game);
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
			anafora_game.life_down();

			graphics::playSound("assets\\explotion.wav", 0.1f, false);
			Explotion* ex = new Explotion(enemy->getX(), enemy->getY(), 50, 50, 15, anafora_game);
			anafora_game.addGameObject(ex);

			return true;
		}
	}

	return false;
}