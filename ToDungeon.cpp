#include "ToDungeon.h"
#include "Battle.h"
#include "Game.h"

ToDungeon::ToDungeon(View *parent, Game * game) : Button(10, 11, 10, sf::Vector2f(657, 407), parent, game)
{

}


ToDungeon::~ToDungeon()
{
}

void ToDungeon::doAction()
{
	new Battle(4, _game);
}