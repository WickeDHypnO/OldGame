#include "Town.h"
#include "ToDungeon.h"
#include "ToGuild.h"
#include "ToTavern.h"
#include "ToBlacksmith.h"
#include "Animation.h"

Town::Town(int texture, Game * parent) : View(texture, parent)
{
	new ToBlacksmith(this, _parent);
	new ToDungeon(this, _parent);
	new ToGuild(this, _parent);
	new ToTavern(this, _parent);
	new Animation(100, this, _parent, 5, sf::seconds(0.25), sf::Vector2f(143, 303));
}


Town::~Town()
{
}