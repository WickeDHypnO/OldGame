#include "ToGuild.h"
#include "View.h"
#include "Game.h"
#include "Player.h"

ToGuild::ToGuild(View *parent, Game * game) : Button(16, 17, 16, sf::Vector2f(396, 223), parent, game)
{

}


ToGuild::~ToGuild()
{
}

void ToGuild::doAction()
{
	_game->getPlayer()->setMaxMana();
}