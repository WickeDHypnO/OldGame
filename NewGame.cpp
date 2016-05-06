#include "NewGame.h"
#include "View.h"
#include "Game.h"
#include "Town.h"

NewGame::NewGame(View *parent, Game * game) : Button(24, 25, 26, sf::Vector2f(324, 433), parent, game)
{

}


NewGame::~NewGame()
{
}

void NewGame::doAction()
{
	new Town(35, _game);
	this->_game->changeView(this->_parent->_parent->findView(town));
	this->_game->changePlayerOwner();
	this->_game->newGame();
}