#include "Battle.h"
#include "Player.h"
#include "Deathprophet.h"
#include "Troll.h"
#include "Game.h"
Battle::Battle(int texture, Game * parent) : View(texture, parent)
{
	int opponent = rand() % 100;
	if (opponent < 50)
		new Deathprophet(47, this, _parent, sf::Vector2f(700,50), _parent->getPlayer());
	else
		new Troll(45, this, _parent, sf::Vector2f(600, 50), _parent->getPlayer());
	this->_parent->changeView(this->_parent->findView(battle));
	this->_parent->changePlayerOwner();
	int j, k;
	for (int i = 0; i < _objects.size(); i++)
	{
		if (dynamic_cast<Enemy*>(_objects[i]))
		{
			j = i;
		}
		else if (dynamic_cast<Player*>(_objects[i]))
		{
			k = i;
		}
	}
	dynamic_cast<Enemy*>(_objects[j])->setOpponent(dynamic_cast<Character*>(_objects[k]));
	dynamic_cast<Player*>(_objects[k])->setOpponent(dynamic_cast<Character*>(_objects[j]));
}


Battle::~Battle()
{
}
