#include "ManaBar.h"
#include "Game.h"

ManaBar::ManaBar(int maxLevel, Character * owner, sf::Vector2f &position, int height, int length, View *parent, Game * game) : StatusBar(maxLevel, 23, owner, height, length, parent, game)
{
	this->setPosition(position);
	_points->setPosition(this->getPosition() + sf::Vector2f(0, -(this->getSize().y / 4)) );
	maxLevel = _maxLevel;
}


ManaBar::~ManaBar()
{
}

void ManaBar::newGame()
{
	_actualLevel = _maxLevel = 230;
}

bool ManaBar::useMana(int count)
{
	if (count > this->_actualLevel)
		return false;
	else
	{
		_actualLevel -= count;
		return true;
	}
}