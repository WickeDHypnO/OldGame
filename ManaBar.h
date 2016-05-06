#pragma once
#include "StatusBar.h"
class ManaBar :
	public StatusBar
{
public:
	ManaBar(int maxLevel, Character * owner, sf::Vector2f &position, int height, int length, View *parent, Game * game);
	~ManaBar();
	void newGame();
	bool useMana(int count);
};

