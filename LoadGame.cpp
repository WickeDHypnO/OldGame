#include "LoadGame.h"
#include "View.h"
#include "Game.h"
#include "Town.h"
#include "Player.h"

LoadGame::LoadGame(View *parent, Game * game) : Button(20, 21, 22, sf::Vector2f(324, 524), parent, game)
{

}


LoadGame::~LoadGame()
{
}

void LoadGame::doAction()
{
	if (this->_game->getPlayer()->loadGame())
	{
		new Town(35, _game);
		this->_game->changeView(this->_parent->_parent->findView(town));
		this->_game->changePlayerOwner();
	}
}
