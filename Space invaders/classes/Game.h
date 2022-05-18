#pragma once

#include "graphics.h"
#include "GameObject.h"
#include "Background.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "Allien.h"
#include "Explotion.h"
#include "Bullet.h"
#include "Life.h"
#include "Score.h"
#include "Menu.h"
#include "configuration.h"
#include <set>

using namespace std;

class Game
{
public:

	// Platos/ypsos parathyrou
	int platosP = PLATOS_PARATHYROU;
	int ypsosP = YPSOS_PARATHYROU;

	// Platos/ypsos kamva
	int platosK = PLATOS_KAMVA;
	int ypsosK = YPSOS_KAMVA;

	string titlos = TITLOS_PARATHYROU;

	// Xexwrista ta xrwmata tou background
	float backR = 0.0f;
	float backG = 0.0f;
	float backB = 0.0f;
	//   H'
	graphics::Brush backBr;

	// Oloklriri i vourtsa gia to xrwma background


   // Domi gia na apothikeuw ta antikeimena (STL vector)
	set<GameObject*> antikeimena;
	Background* background;
	Score* score;
	Life* lifes;
	Menu* m;


	bool isGameOver;

	float lastTime;

	Game()
	{
		lastTime = 0;
		isGameOver = false;


		background = new Background(platosK / 2, ypsosK / 2, platosK, ypsosK, *this);
		backBr.texture = "assets\back.png";
		score = new Score(50, 50, 50, 50, *this);
		lifes = new Life(platosK - 150, 50, 50, 50, *this);
		m = new Menu(platosK / 2, ypsosK / 2, 200, 350, *this);

		//antikeimena.emplace(background);
		antikeimena.emplace(new Spaceship(platosK / 2, ypsosK - 50, 80, 80, 32, 0, *this));
		antikeimena.emplace(score);
		antikeimena.emplace(lifes);
		//antikeimena.emplace(backround);


		//for (int i = 0; i < 13; i++)
		{
			//antikeimena.emplace(new Enemy(70, 150, 40, 40, 32, *this));
			antikeimena.emplace(new Allien(70, 150, 40, 40, 32, *this));
			//antikeimena.emplace(new Enemy(120 * (i + 1), 150, 40, 40, 32, *this));
		}
	}


	void score_up()
	{
		score->auxiseScore();
	}

	void life_down()
	{
		lifes->meiwseLife();
	}

	// Tha kalesei oles tis upadate twn antikeimenwn
	void update()
	{
		if (m->isOn() == true)
		{
			m->update();
			return;
		}

		//if (isGameOver == false)
		{
			if (lifes->getLifes() == 0)
			{
				// Game Over
				isGameOver = true;
			}

			// Dimiourgw mia seira exthrwn an exooun perasei 3''
			float curTime = graphics::getGlobalTime();
			if (curTime - lastTime >= ((4 - m->get_selector()) * 1000))
			{
				for (int i = 0; i < 13; i++)
				{
					antikeimena.emplace(new Enemy(70 * (i + 1), 150, 40, 40, 32, *this));
					antikeimena.emplace(new Allien(70 * (i + 1), 250, 40, 40, 32, *this));
				}

				lastTime = curTime;
			}

			for (auto a : antikeimena)
			{
				a->update();
			}

			// Vlepoume an exei vgei i sfaira ektos h o xenos h teleiwsei h ekrixi
			for (auto a : antikeimena)
			{
				Bullet* s = dynamic_cast<Bullet*>(a);

				if (s != nullptr && s->is_into_canvas() == false)
				{
					delete a;					// Delete apo tin mnimi
					antikeimena.erase(a);		// erase gia na vgei apo to set
					break;
				}

				Enemy* x = dynamic_cast<Enemy*>(a);

				if (x != nullptr && x->is_into_canvas() == false)
				{
					delete a;					// Delete apo tin mnimi
					antikeimena.erase(a);		// erase gia na vgei apo to set
					break;
				}

				Allien* z = dynamic_cast<Allien*>(a);

				if (z != nullptr && z->is_into_canvas() == false)
				{
					delete a;					// Delete apo tin mnimi
					antikeimena.erase(a);		// erase gia na vgei apo to set
					break;
				}

				Explotion* ex = dynamic_cast<Explotion*>(a);

				if (ex != nullptr && ex->isDead() == true)
				{
					delete a;					// Delete apo tin mnimi
					antikeimena.erase(a);		// erase gia na vgei apo to set
					break;
				}
			}

			// Kanei olous tous syndiasmous gia na doume poios sygkrouetai
			// me poion
			for (auto a : antikeimena)
			{
				for (auto b : antikeimena)
				{
					// An exoume sygkrousi
					if (a->checkColision(b) == true)
					{
						// An einai 
						if (dynamic_cast<Enemy*>(a) != nullptr)
						{
							deleteGameObject(a);
						}
						else if (dynamic_cast<Bullet*>(a) != nullptr)
						{
							deleteGameObject(a);
						}
						else if (dynamic_cast<Allien*>(a) != nullptr)
						{
							deleteGameObject(a);
						}

						if (dynamic_cast<Enemy*>(b) != nullptr)
						{
							deleteGameObject(b);
						}
						else if (dynamic_cast<Bullet*>(b) != nullptr)
						{
							deleteGameObject(b);
						}
						else if (dynamic_cast<Allien*>(b) != nullptr)
						{
							deleteGameObject(b);
						}

						return;			// prepei na to kanei return gia na min synexisei h for
					}
				}
			}

		}
	}


	// Tha kalesei oles tis draw twn antikeimenwn
	void draw()
	{
		background->draw();

		if (m->isOn() == true)
		{
			m->draw();
			return;
		}

		for (auto x : antikeimena)
		{
			x->draw();
		}

		if (isGameOver == true)
		{
			graphics::Brush br;
			br.fill_opacity = 50.0;
			graphics::drawText(400, 100, 50, "Game Over", br);
		}
	}

	~Game()
	{
		for (auto x : antikeimena)
		{
			delete x;
		}
	}


	// Psaxnei na svisei to antikeimeno go apo to set
	
	
	void deleteGameObject(GameObject* go)
	{
		antikeimena.erase(antikeimena.find(go));
		delete go;
	}

	void addGameObject(GameObject* go)
	{
		antikeimena.emplace(go);
	}
};