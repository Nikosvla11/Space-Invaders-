#pragma once

#include "Game.h"
#include "Explotion.h"


Explotion::Explotion(float x, float y, float platos, float ypsos, float aktina, Game& game) : GameObject(x, y, platos, ypsos, aktina, game)
{
	br.texture = "assets\\explotion.png";
	br.outline_opacity = 0.0;

	time = graphics::getGlobalTime();
	dead = false;
}


void Explotion::draw()
{
	if (!dead)
		graphics::drawRect(x, y, 50, 50, br);
}


void Explotion::update()
{
	float curTime = graphics::getGlobalTime();

	if (curTime - time >= 250)
	{
		dead = true;
		time = curTime;
	}
}

bool Explotion::checkColision(GameObject* go)
{
	return false;
}


bool Explotion::isDead()
{
	return dead;
}