#include "Game.h"
#include "Spaceship.h"
#include "GameObject.h"

Enemy::Enemy(int x, int y, int platos, int ypos, int aktina, Game& game)
	: GameObject(x, y, platos, ypos, aktina, game)
{
	fX = 1;
	fY = 1;
	life = 1;
	br.texture = "assets\\enemy2.png";
	br.outline_opacity = 0.0f;
}

void Enemy::draw()
{
	graphics::drawRect(x, y, platos, ypsos, br);
}

void Enemy::update()
{
	//x = x + fX;
	y = y + fX * graphics::getDeltaTime() / 10.0f;
	
}
//*bool Enemy::has_life()
//{
//	if (life == 0)
//		return false;
//	else
//		return true;
//}
//void Enemy::katastrofi()
//{
//	life = 0;
//}
// Eimai xenos, ara mporw na sygkroustw me diastimoploio h sfaira
bool Enemy::checkColision(GameObject* go)
{
	Spaceship* d = dynamic_cast<Spaceship*> (go);

	// Gia na dw an einai diastimoploio kanw cast.
	// An petyxei to d den tha einai nullptr
	if (d != nullptr)
	{
		float apostasi_kentrwn = sqrt(pow(x - (d->getX()), 2) + pow(y - (d->getY()), 2));

		// Estw oti exw sygkrousi
		if (apostasi_kentrwn - aktina - d->getR() < 0)
		{
			anafora_game.life_down();
			bounce();

			return true;
		}
		
	}

	//Diastimoploio* d = dynamic_cast<Diastimoploio*> (go);

	return false;
}


void Enemy::bounce()
{
	//fY = -fY;
	//fX = -fX;
}

bool Enemy::is_into_canvas()
{
	if (x < 0 || x > PLATOS_KAMVA || y < 0 || y > YPSOS_KAMVA)
		return false;
	else
		return true;
}