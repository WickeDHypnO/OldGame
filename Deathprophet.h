#pragma once
#include "Enemy.h"
class Deathprophet :
	public Enemy
{
	bool up = false;
public:
	Deathprophet(int texture, View *parent, Game * game, sf::Vector2f position , Character * player);
	~Deathprophet();
	void Play();
	void Update();
};

