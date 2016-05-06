#include "Avatar.h"
#include "View.h"
#include "Game.h"
#include "Player.h"
Avatar::Avatar(View *parent, int texture, Player * player, Game * game) : GameObject(parent, game)
{
	_player = player;
	this->_texture = _game->findTexture(texture);
	this->setTexture(_texture);
	this->setSize(sf::Vector2f(_texture->getSize()));
	this->setPosition(21, 574);
}


Avatar::~Avatar()
{
}

void Avatar::Update()
{
	
}

void Avatar::setView(View *parent)
{
	_parent = parent;
}