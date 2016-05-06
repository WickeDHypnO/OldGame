#pragma once
#include "Header.h"
class View;
class Game;
class GameObject :public sf::RectangleShape
{
public:
	GameObject(View *parent, Game * game);
	~GameObject();
	virtual void Update() = 0;
protected:
	Game * _game;
	View * _parent;
};