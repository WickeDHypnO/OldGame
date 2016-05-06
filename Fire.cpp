#include "Fire.h"
#include "View.h"
#include "Game.h"

Fire::Fire(View *parent, Game * game) : Animation(100, parent, game, 5, sf::seconds(0.25))
{
	setPosition(sf::Vector2f(143, 303));
}


Fire::~Fire()
{
}
