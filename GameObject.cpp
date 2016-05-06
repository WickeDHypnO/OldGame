#include "GameObject.h"
#include "View.h"

GameObject::GameObject(View* parent, Game * game) : sf::RectangleShape()
{
	_game = game;
	_parent = parent;
	if (_parent)
		_parent->addObject(this);
}


GameObject::~GameObject()
{
}