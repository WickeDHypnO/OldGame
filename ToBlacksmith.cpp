#include "ToBlacksmith.h"
#include "View.h"
#include "Game.h"
#include "Shop.h"

ToBlacksmith::ToBlacksmith(View *parent, Game * game) : Button(6, 7, 6, sf::Vector2f(118, 234), parent, game)
{

}


ToBlacksmith::~ToBlacksmith()
{
}

void ToBlacksmith::doAction()
{
	new Shop(99, _game);
	this->_game->changeView(this->_parent->_parent->findView(shop));
	this->_game->changePlayerOwner();
}