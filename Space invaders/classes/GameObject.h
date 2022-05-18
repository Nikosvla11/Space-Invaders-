#pragma once

#include "Game.h"
#include "graphics.h"

using namespace std;



class GameObject
{
protected:

	// Syntetagmenes
	float x;
	float y;

	// Diastaseis
	int platos;
	int ypsos;

	// Xreiazetai gia tis sygkrouseis
	int aktina;

	graphics::Brush br;			// Vourtsa giati kathe antikeimeno tha exei eikonidio

	// Anafora se olo to Game, gia na exei prosvasi to antikeimeno stis diastaseis
	// tou paixnidiou
	class Game& anafora_game;			// Thymame na rwtisw giati ?

public:

	GameObject(int x, int y, int platos, int ypos, int aktina, class Game& g) :anafora_game(g)
	{
		this->x = x;
		this->y = y;

		this->platos = platos;
		this->ypsos = ypos;

		this->aktina = aktina;

		// Den tha arxikopoihsw tin vourtsa
		// H klash GameObject einai afirimeni, den tha kollage na exei kapoio
		// sygkekrimeno xrwma
	}

	virtual void update() = 0;
	virtual void draw() = 0;

	virtual bool checkColision(GameObject* go) = 0;


	virtual ~GameObject()
	{

	}

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

	float getR()
	{
		return aktina;
	}
};
