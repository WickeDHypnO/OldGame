#include "ExitGame.h"
#include "View.h"
#include "Game.h"

ExitGame::ExitGame(View *parent, Game * game) : Button(12, 13, 14, sf::Vector2f(324, 616), parent, game)
{

}


ExitGame::~ExitGame()
{
}

void ExitGame::doAction()
{
	this->_game->mWindow.close();
}