#pragma once
#include "Enemy.h"
class Troll :
	public Enemy
{
public:
	Troll(int texture, View *parent, Game * game, sf::Vector2f position, Character * player);
	~Troll();
	void Play();
	void Update();
};

