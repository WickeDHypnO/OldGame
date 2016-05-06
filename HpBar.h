#pragma once
#include "StatusBar.h"
class HpBar :
	public StatusBar
{
public:
	HpBar(int maxLevel, Character * owner, sf::Vector2f &position, int height, int length, View *parent, Game * game);
	~HpBar();
	void getDamage(int damage);
	void newGame();
};

