#include "ToTavern.h"
#include "View.h"
#include "Game.h"
#include "Player.h"
ToTavern::ToTavern(View *parent, Game * game) : Button(33, 34, 33, sf::Vector2f(560, 228), parent, game)
{

}


ToTavern::~ToTavern()
{
}

void ToTavern::doAction()
{
	_game->_player->setMaxHealth();
}