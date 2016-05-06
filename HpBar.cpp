#include "HpBar.h"
#include "Game.h"
#include "Enemy.h"

HpBar::HpBar(int maxLevel, Character * owner, sf::Vector2f &position, int height, int length, View *parent, Game * game) : StatusBar(maxLevel, 19, owner, height, length, parent, game)
{
	this->setPosition(position);
	_points->setPosition(this->getPosition() + sf::Vector2f(0,-(this->getSize().y /4)));
	_maxLevel = maxLevel;
}


HpBar::~HpBar()
{

}

void HpBar::getDamage(int damage)
{
	if (damage < 0)
	{
		if (_actualLevel - damage >= _maxLevel)
			_actualLevel = _maxLevel;
		else
			_actualLevel -= damage;
	}
	else
	{
		if (_actualLevel - damage >= 0)
			_actualLevel -= damage;
		else
		{
			_actualLevel = 0;
			if (dynamic_cast<Enemy*>(_owner))
				_game->wonGame();
			else
				_game->lostGame();
		}
	}
}

void HpBar::newGame()
{
	_actualLevel = _maxLevel = 350;
}