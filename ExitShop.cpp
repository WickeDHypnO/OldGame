#include "ExitShop.h"
#include "View.h"
#include "Game.h"
#include "Town.h"

ExitShop::ExitShop(View *parent, Game * game) : Button(75, 76, 75, sf::Vector2f(841, 398), parent, game)
{

}


ExitShop::~ExitShop()
{
}

void ExitShop::doAction()
{
	new Town(35, _game);
	this->_game->changeView(this->_parent->_parent->findView(town));
	this->_game->changePlayerOwner();
}